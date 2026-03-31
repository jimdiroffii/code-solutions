#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H);
    fgetc(stdin);

    char *arr = malloc(L * H * 27 * sizeof(char));

    char T[257] = "";
    scanf("%[^\n]", T);
    fgetc(stdin);
    for (int i = 0; i < H; i++)
    {
        char ROW[1025] = "";
        scanf("%[^\n]", ROW);
        fgetc(stdin);
        // fprintf(stderr, "%s", ROW);
        int row_len = L * 27;
        for (int j = 0; j < row_len; ++j)
        {
            arr[(i * row_len) + j] = ROW[j];
        }
        // for (int j = 0; j < row_len; ++j)
        // {
        //     fprintf(stderr, "%c", arr[(i * row_len) + j]);
        // }
        // fprintf(stderr, "\n");
    }

    char ch;
    // char *str = "abcABC123";
    int str_len = strlen(T);
    int n = 0;
    for (int j = 0; j < H; ++j)
    {
        for (int i = 0; i < str_len; ++i)
        {
            ch = T[i];
            if (ch >= 'A' && ch <= 'Z')
            {
                n = ch - 'A';
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                n = ch - 'a';
            }
            else
            {
                n = 26;
            }

            for (int k = 0; k < L; ++k)
            {
                // fprintf(stderr, "%c", arr[((n * L) + k) + (L * 27 * j)]);
                printf("%c", arr[((n * L) + k) + (L * 27 * j)]);
            }
        }
        // fprintf(stderr, "\n");
        printf("\n");
    }
    // fprintf(stderr, "%i\n", n);

    // fprintf(stderr, "%c%c%c%c\n", arr[((n * L) + 0) + (4 * 27 * 0)], arr[((n * L) + 1) + (4 * 27 * 0)], arr[((n * L) + 2) + (4 * 27 * 0)], arr[((n * L) + 3) + (4 * 27 * 0)]);
    // fprintf(stderr, "%c%c%c%c\n", arr[((n * L) + 0) + (4 * 27 * 1)], arr[((n * L) + 1) + (4 * 27 * 1)], arr[((n * L) + 2) + (4 * 27 * 1)], arr[((n * L) + 3) + (4 * 27 * 1)]);
    // fprintf(stderr, "%c%c%c%c\n", arr[((n * L) + 0) + (4 * 27 * 2)], arr[((n * L) + 1) + (4 * 27 * 2)], arr[((n * L) + 2) + (4 * 27 * 2)], arr[((n * L) + 3) + (4 * 27 * 2)]);
    // fprintf(stderr, "%c%c%c%c\n", arr[((n * L) + 0) + (4 * 27 * 3)], arr[((n * L) + 1) + (4 * 27 * 3)], arr[((n * L) + 2) + (4 * 27 * 3)], arr[((n * L) + 3) + (4 * 27 * 3)]);
    // fprintf(stderr, "%c%c%c%c\n", arr[((n * L) + 0) + (4 * 27 * 4)], arr[((n * L) + 1) + (4 * 27 * 4)], arr[((n * L) + 2) + (4 * 27 * 4)], arr[((n * L) + 3) + (4 * 27 * 4)]);

    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    // fprintf(stderr, "L: %i, H: %i\n", L, H);
    free(arr);
    return 0;
}