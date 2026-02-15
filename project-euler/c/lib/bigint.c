#include "bigint.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define BIGINT_BASE 1000000000u // 10^9
#define BIGINT_BASE_DIGS 9

static void bi_set_zero(BigInt *x)
{
    x->limbs = (uint32_t *)malloc(sizeof(uint32_t));
    if (!x->limbs)
    {
        x->len = 0;
        return;
    }
    x->limbs[0] = 0;
    x->len = 1;
}

void bi_free(BigInt *x)
{
    if (!x)
        return;
    free(x->limbs);
    x->limbs = NULL;
    x->len = 0;
}

static void bi_normalize(BigInt *x)
{
    while (x->len > 1 && x->limbs[x->len - 1] == 0)
    {
        x->len--;
    }
}

// Multiply x by 10 (in-place). Addition-only “neighbor” operation.
// This is used to build 10^N without needing general multiplication.
static bool bi_mul10_inplace(BigInt *x)
{
    uint64_t carry = 0;
    for (size_t i = 0; i < x->len; i++)
    {
        uint64_t v = (uint64_t)x->limbs[i] * 10ull + carry;
        x->limbs[i] = (uint32_t)(v % BIGINT_BASE);
        carry = v / BIGINT_BASE;
    }
    if (carry)
    {
        uint32_t *p = (uint32_t *)realloc(x->limbs, (x->len + 1) * sizeof(uint32_t));
        if (!p)
            return false;
        x->limbs = p;
        x->limbs[x->len] = (uint32_t)carry;
        x->len += 1;
    }
    return true;
}

static bool bi_pow10(BigInt *out, size_t exp)
{
    bi_free(out);
    bi_set_zero(out);
    if (!out->limbs)
        return false;

    // Start at 1
    out->limbs[0] = 1;

    // Multiply by 10 exp times => 10^exp
    for (size_t i = 0; i < exp; i++)
    {
        if (!bi_mul10_inplace(out))
        {
            bi_free(out);
            return false;
        }
    }
    bi_normalize(out);
    return true;
}

static const char *skip_spaces(const char *s)
{
    while (*s && isspace((unsigned char)*s))
        s++;
    return s;
}

static bool parse_uint_dec(const char *s, size_t *out_val, const char **out_end)
{
    // Parse a non-negative integer that fits in size_t (used for exponent).
    // Returns false if no digits.
    size_t v = 0;
    const char *p = s;
    if (!isdigit((unsigned char)*p))
        return false;

    while (isdigit((unsigned char)*p))
    {
        unsigned digit = (unsigned)(*p - '0');
        // basic overflow-safe-ish check (best effort)
        if (v > (SIZE_MAX - digit) / 10)
            return false;
        v = v * 10 + digit;
        p++;
    }
    *out_val = v;
    if (out_end)
        *out_end = p;
    return true;
}

static bool bi_from_dec_digits(BigInt *out, const char *digits)
{
    // digits must be only [0-9]+ (no sign), already trimmed of leading spaces.
    // We will parse in 9-digit chunks from the end.
    bi_free(out);

    // Skip leading zeros but preserve one zero if all zeros
    while (*digits == '0')
        digits++;
    if (*digits == '\0')
    {
        bi_set_zero(out);
        return out->limbs != NULL;
    }

    size_t nd = strlen(digits);
    size_t limbs_needed = (nd + BIGINT_BASE_DIGS - 1) / BIGINT_BASE_DIGS;

    out->limbs = (uint32_t *)calloc(limbs_needed, sizeof(uint32_t));
    if (!out->limbs)
    {
        out->len = 0;
        return false;
    }
    out->len = limbs_needed;

    size_t limb_index = 0;
    for (size_t end = nd; end > 0;)
    {
        size_t start = (end >= BIGINT_BASE_DIGS) ? (end - BIGINT_BASE_DIGS) : 0;
        size_t chunk_len = end - start;

        char buf[BIGINT_BASE_DIGS + 1];
        memcpy(buf, digits + start, chunk_len);
        buf[chunk_len] = '\0';

        unsigned long v = strtoul(buf, NULL, 10);
        out->limbs[limb_index++] = (uint32_t)v;

        end = start;
    }

    bi_normalize(out);
    return true;
}

bool bi_from_string(BigInt *out, const char *s)
{
    if (!out || !s)
        return false;

    s = skip_spaces(s);

    // Support "10^N" exactly (with optional spaces around '^' not supported here)
    if (s[0] == '1' && s[1] == '0' && s[2] == '^')
    {
        size_t exp = 0;
        const char *p = s + 3;
        if (!parse_uint_dec(p, &exp, &p))
            return false;
        p = skip_spaces(p);
        if (*p != '\0')
            return false;
        return bi_pow10(out, exp);
    }

    // Otherwise: must be plain decimal digits
    const char *p = s;
    if (!isdigit((unsigned char)*p))
        return false;
    while (isdigit((unsigned char)*p))
        p++;

    const char *tail = skip_spaces(p);
    if (*tail != '\0')
        return false;

    // Copy just the digit part into a temporary buffer so bi_from_dec_digits() can use strlen safely
    size_t n = (size_t)(p - s);
    char *tmp = (char *)malloc(n + 1);
    if (!tmp)
        return false;
    memcpy(tmp, s, n);
    tmp[n] = '\0';

    bool ok = bi_from_dec_digits(out, tmp);
    free(tmp);
    return ok;
}

bool bi_add(BigInt *out, const BigInt *a, const BigInt *b)
{
    if (!out || !a || !b || !a->limbs || !b->limbs || a->len == 0 || b->len == 0)
    {
        return false;
    }

    size_t n = a->len;
    size_t m = b->len;
    size_t max = (n > m) ? n : m;

    uint32_t *res = (uint32_t *)calloc(max + 1, sizeof(uint32_t));
    if (!res)
        return false;

    uint64_t carry = 0;
    for (size_t i = 0; i < max; i++)
    {
        uint64_t ai = (i < n) ? a->limbs[i] : 0;
        uint64_t bi = (i < m) ? b->limbs[i] : 0;
        uint64_t sum = ai + bi + carry;

        res[i] = (uint32_t)(sum % BIGINT_BASE);
        carry = sum / BIGINT_BASE;
    }
    res[max] = (uint32_t)carry;

    bi_free(out);
    out->limbs = res;
    out->len = max + 1;
    bi_normalize(out);
    return true;
}

char *bi_to_string(const BigInt *x)
{
    if (!x || !x->limbs || x->len == 0)
        return NULL;

    // Worst-case decimal digits:
    // top limb up to 9 digits, each remaining limb exactly 9 digits.
    size_t max_chars = x->len * BIGINT_BASE_DIGS + 1; // +1 for '\0'
    char *buf = (char *)malloc(max_chars);
    if (!buf)
        return NULL;

    // Print highest limb without zero-padding
    size_t i = x->len - 1;
    int written = snprintf(buf, max_chars, "%u", x->limbs[i]);
    if (written < 0)
    {
        free(buf);
        return NULL;
    }
    size_t pos = (size_t)written;

    // Print remaining limbs with zero-padding to 9 digits
    while (i > 0)
    {
        i--;
        // Ensure we don't overflow (max_chars is generously sized)
        written = snprintf(buf + pos, max_chars - pos, "%09u", x->limbs[i]);
        if (written < 0)
        {
            free(buf);
            return NULL;
        }
        pos += (size_t)written;
    }

    return buf;
}
