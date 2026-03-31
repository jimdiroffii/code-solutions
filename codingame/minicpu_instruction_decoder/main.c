#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Decode and execute the MiniCPU bytecode program.
 **/

void mov(uint8_t *r, uint8_t val)
{
    *r = val;
    return;
}

void add(uint8_t *r1, uint8_t *r2)
{
    *r1 += *r2;
    return;
}

void sub(uint8_t *r1, uint8_t *r2)
{
    *r1 -= *r2;
    return;
}

void mul(uint8_t *r1, uint8_t *r2)
{
    *r1 *= *r2;
    return;
}

void inc(uint8_t *r)
{
    *r += 1;
    return;
}

void dec(uint8_t *r)
{
    *r -= 1;
    return;
}

int main()
{
    // Space-separated hex bytes representing CPU instructions
    char program[501] = "";
    scanf("%[^\n]", program);

    uint8_t R0 = 0;
    uint8_t R1 = 0;
    uint8_t R2 = 0;
    uint8_t R3 = 0;
    uint8_t *arr[4] = {&R0, &R1, &R2, &R3};

    int pos = 0;
    int consumed;

    unsigned int byte;
    bool halted = false;
    while (!halted && sscanf(program + pos, "%x%n", &byte, &consumed) == 1)
    {
        uint8_t b = (uint8_t)byte;
        pos += consumed;
        fprintf(stderr, "%x\n", b);
        switch (b)
        {
        case 0x01:
        {
            fprintf(stderr, "mov\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r = (uint8_t)byte;
            fprintf(stderr, "r: %d\n", r);
            pos += consumed;
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t val = (uint8_t)byte;
            fprintf(stderr, "val: %d\n", val);
            pos += consumed;
            mov(arr[r], val);
            break;
        }
        case 0x02:
        {
            fprintf(stderr, "add\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r1 = (uint8_t)byte;
            fprintf(stderr, "r1: %d\n", r1);
            pos += consumed;
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r2 = (uint8_t)byte;
            fprintf(stderr, "r2: %d\n", r2);
            pos += consumed;
            add(arr[r1], arr[r2]);
            break;
        }
        case 0x03:
        {
            fprintf(stderr, "sub\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r1 = (uint8_t)byte;
            fprintf(stderr, "r1: %d\n", r1);
            pos += consumed;
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r2 = (uint8_t)byte;
            fprintf(stderr, "r2: %d\n", r2);
            pos += consumed;
            sub(arr[r1], arr[r2]);
            break;
        }
        case 0x04:
        {
            fprintf(stderr, "mul\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r1 = (uint8_t)byte;
            fprintf(stderr, "r1: %d\n", r1);
            pos += consumed;
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r2 = (uint8_t)byte;
            fprintf(stderr, "r2: %d\n", r2);
            pos += consumed;
            mul(arr[r1], arr[r2]);
            break;
        }
        case 0x05:
        {
            fprintf(stderr, "inc\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r = (uint8_t)byte;
            fprintf(stderr, "r1: %d\n", r);
            pos += consumed;
            inc(arr[r]);
            break;
        }
        case 0x06:
        {
            fprintf(stderr, "dec\n");
            sscanf(program + pos, "%x%n", &byte, &consumed);
            uint8_t r = (uint8_t)byte;
            fprintf(stderr, "r1: %d\n", r);
            pos += consumed;
            dec(arr[r]);
            break;
        }
        case 0xFF:
            fprintf(stderr, "halt\n");
            halted = true;
            break;
        default:
            fprintf(stderr, "unknown opcode\n");
            halted = true;
            break;
        }
    }

    // Print the final value of each register R0, R1, R2, R3, one value per line
    printf("%d\n%d\n%d\n%d\n", R0, R1, R2, R3);

    return 0;
}