#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void debug_2d_arr(char arr[][8], int size)
{
    fprintf(stderr, "\n");
    for (int i = 0; i < size; ++i)
    {
        fprintf(stderr, "  ");
        for (int j = 0; j < size; ++j)
        {
            fprintf(stderr, "%c", arr[i][j]);
        }
        fprintf(stderr, "\n");
    }
}

int main()
{
    char pieces[16] = "";
    scanf("%[^\n]", pieces); fgetc(stdin);
    fprintf(stderr, "pieces: [%s]\n", pieces);

    char arr[8][8] = {0};

    fprintf(stderr, "  abcdefgh\n\n");

    for (int i = 0, j = 8; i < 8; ++i, --j) {
        char sline[9] = "";
        scanf("%[^\n]", sline); fgetc(stdin);
        fprintf(stderr, "%d %s %d\n", j, sline, j);

        for (int k = 0; k < 8; ++k)
        {
            if (strchr(pieces, toupper(sline[k]))) arr[i][k] = sline[k];
            else arr[i][k] = ' ';
        }
    }

    fprintf(stderr, "\n  abcdefgh\n");
    
    debug_2d_arr(arr, 8);

    fprintf(stderr, "\n  abcdefgh\n\n");

    int position = 1;

    for (int i = 0, j = 8; i < 8; ++i, --j) {
        char eline[9] = "";
        scanf("%[^\n]", eline); fgetc(stdin);
        fprintf(stderr, "%d %s %d\n", j, eline, j);

        
    }

    fprintf(stderr, "\n  abcdefgh\n\n");

    printf("e2-e3\nOther");
    return 0;
}
