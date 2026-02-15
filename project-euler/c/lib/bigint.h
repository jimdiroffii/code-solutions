#ifndef BIGINT_H_
#define BIGINT_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    uint32_t *limbs;
    size_t len;
} BigInt;

bool bi_from_string(BigInt *out, const char *s);
bool bi_add(BigInt *out, const BigInt *a, const BigInt *b);
char *bi_to_string(const BigInt *x);
void bi_free(BigInt *x);

#endif // BIGINT_H_