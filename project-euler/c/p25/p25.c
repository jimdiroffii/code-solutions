#include <stdio.h>
#include <stdlib.h>
#include "../lib/bigint.h"

int main()
{
    const char *a = "10^100000";
    const char *b = "1";

    BigInt A = {0};
    BigInt B = {0};
    BigInt C = {0};

    if (!bi_from_string(&A, a))
    {
        fprintf(stderr, "Failed to parse a: %s\n", a);
        return 1;
    }

    if (!bi_from_string(&B, b))
    {
        fprintf(stderr, "Failed to parse b: %s\n", b);
        bi_free(&A);
        return 1;
    }

    if (!bi_add(&C, &A, &B))
    {
        fprintf(stderr, "Addition failed\n");
        bi_free(&A);
        bi_free(&B);
        return 1;
    }

    char *out = bi_to_string(&C);
    if (!out)
    {
        fprintf(stderr, "Failed to convert result to string\n");
        bi_free(&A);
        bi_free(&B);
        bi_free(&C);
        return 1;
    }

    printf("%s + %s = %s\n", a, b, out);
    free(out);
    bi_free(&A);
    bi_free(&B);
    bi_free(&C);

    return 0;
}
