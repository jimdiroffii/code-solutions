#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Calculates the midpoint between two numbers, truncates decimal
 *
 * Used when moving left or up across the grid
 */
int midpoint(int num1, int num2)
{
    return (num1 + num2) / 2;
}

/**
 * Calculates the midpoint between two numbers, adds one (round up)
 *
 * Used when moving right or down across the grid
 */
int midpoint_ceil(int num1, int num2)
{
    return ((num1 + num2) / 2) + 1;
}

int main()
{
    int W, H, N, X0, Y0;
    scanf("%d%d%d%d%d", &W, &H, &N, &X0, &Y0);
    fprintf(stderr, "W: %d\nH: %d\nN: %d\nX0: %d\nY0: %d\n", W, H, N, X0, Y0);

    // Search Space Bounds
    int x_lower = 0;
    int x_upper = W - 1;
    int y_lower = 0;
    int y_upper = H - 1;

    while (1)
    {
        // The direction of the bombs from batman's current location
        // (U, UR, R, DR, D, DL, L or UL)
        char bomb_dir[4] = "";
        scanf("%s", bomb_dir);
        fprintf(stderr, "S: %s\n", bomb_dir);
        int bomb_dir_enum = -1;
        if (strcmp("U", bomb_dir) == 0)
            bomb_dir_enum = 0;
        else if (strcmp("UR", bomb_dir) == 0)
            bomb_dir_enum = 1;
        else if (strcmp("R", bomb_dir) == 0)
            bomb_dir_enum = 2;
        else if (strcmp("DR", bomb_dir) == 0)
            bomb_dir_enum = 3;
        else if (strcmp("D", bomb_dir) == 0)
            bomb_dir_enum = 4;
        else if (strcmp("DL", bomb_dir) == 0)
            bomb_dir_enum = 5;
        else if (strcmp("L", bomb_dir) == 0)
            bomb_dir_enum = 6;
        else if (strcmp("UL", bomb_dir) == 0)
            bomb_dir_enum = 7;
        else
        {
            fprintf(stderr, "Unknown direction");
            return 1;
        }
        fprintf(stderr, "E: %d\n", bomb_dir_enum);

        switch (bomb_dir_enum)
        {
        case 0: // U
        {
            x_lower = X0;
            x_upper = X0;
            y_upper = Y0 - 1;

            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        case 1: // UR
        {
            x_lower = X0 + 1;
            y_upper = Y0 - 1;

            X0 = midpoint(x_lower, x_upper);
            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        case 2: // R
        {
            x_lower = X0 + 1;
            y_lower = Y0;
            y_upper = Y0;

            X0 = midpoint(x_lower, x_upper);
            break;
        }
        case 3: // DR
        {
            x_lower = X0 + 1;
            y_lower = Y0 + 1;

            X0 = midpoint(x_lower, x_upper);
            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        case 4: // D
        {
            x_lower = X0;
            x_upper = X0;
            y_lower = Y0 + 1;

            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        case 5: // DL
        {
            x_upper = X0 - 1;
            y_lower = Y0 + 1;

            X0 = midpoint(x_lower, x_upper);
            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        case 6: // L
        {
            x_upper = X0 - 1;
            y_lower = Y0;
            y_upper = Y0;

            X0 = midpoint(x_lower, x_upper);
            break;
        }
        case 7: // UL
        {
            x_upper = X0 - 1;
            y_upper = Y0 - 1;

            X0 = midpoint(x_lower, x_upper);
            Y0 = midpoint(y_lower, y_upper);
            break;
        }
        default:
        {
            break;
        }
        }
        fprintf(stderr, "X0: %d, Y0: %d", X0, Y0);
        printf("%d %d\n", X0, Y0);
    }

    return 0;
}