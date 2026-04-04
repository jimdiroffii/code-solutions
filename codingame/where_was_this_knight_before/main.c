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
    char pieces[32] = "";
    scanf("%[^\n]", pieces);
    fgetc(stdin);
    fprintf(stderr, "pieces: [%s]\n", pieces);

    char arr[8][8] = {0};

    fprintf(stderr, "  abcdefgh\n\n");

    // Read the first board
    for (int i = 0, j = 8; i < 8; ++i, --j)
    {
        char sline[9] = "";
        scanf("%[^\n]", sline);
        fgetc(stdin);
        fprintf(stderr, "%d %s %d\n", j, sline, j);

        for (int k = 0; k < 8; ++k)
        {
            if (strchr(pieces, toupper(sline[k])))
                arr[i][k] = sline[k];
            else
                arr[i][k] = ' ';
        }
    }

    fprintf(stderr, "\n  abcdefgh\n");
    debug_2d_arr(arr, 8);
    fprintf(stderr, "\n  abcdefgh\n\n");

    // Track move details
    int orig_r = -1, orig_c = -1;
    int dest_r = -1, dest_c = -1;
    bool is_capture = false;

    // Read and diff the second board
    for (int i = 0, j = 8; i < 8; ++i, --j)
    {
        char eline[9] = "";
        scanf("%[^\n]", eline);
        fgetc(stdin);
        fprintf(stderr, "%d %s %d\n", j, eline, j);

        for (int k = 0; k < 8; ++k)
        {
            // Determine what piece is currently on this square (or if it's empty)
            char current_piece = ' ';
            if (strchr(pieces, toupper(eline[k])))
            {
                current_piece = eline[k];
            }

            // Compare against the first board
            if (arr[i][k] != current_piece)
            {
                if (current_piece == ' ')
                {
                    // Board 1 had a piece, Board 2 is empty. This is where it moved FROM.
                    orig_r = i;
                    orig_c = k;
                }
                else
                {
                    // Board 2 has a piece that differs from Board 1. This is where it moved TO.
                    dest_r = i;
                    dest_c = k;

                    // If Board 1 wasn't empty here, it means a piece was captured.
                    if (arr[i][k] != ' ')
                    {
                        is_capture = true;
                    }
                }
            }
        }
    }

    fprintf(stderr, "\n  abcdefgh\n\n");

    // Determine if the piece moved like a knight
    int dx = abs(orig_c - dest_c);
    int dy = abs(orig_r - dest_r);
    bool is_knight = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);

    // Format coordinates
    // Columns map from 0-7 to 'a'-'h'
    // Rows map from 0-7 to 8-1
    char orig_col = 'a' + orig_c;
    int orig_row = 8 - orig_r;
    char dest_col = 'a' + dest_c;
    int dest_row = 8 - dest_r;
    char separator = is_capture ? 'x' : '-';

    // Output results
    printf("%c%d%c%c%d\n", orig_col, orig_row, separator, dest_col, dest_row);
    printf("%s\n", is_knight ? "Knight" : "Other");

    return 0;
}