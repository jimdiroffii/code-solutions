#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    bool isNode;
} node;

int main()
{
    int width;
    scanf("%d", &width);
    int height;
    scanf("%d", &height);
    fgetc(stdin);

    node grid[width][height];

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            grid[j][i].isNode = false;
        }
    }

    for (int i = 0; i < height; i++)
    {
        char line[32] = "";
        scanf("%[^\n]", line);
        fgetc(stdin);
        for (int j = 0; j < width; ++j)
        {
            if (line[j] == '0')
                grid[j][i].isNode = true;
        }
    }

    for (int i = 0, j = 0; i < width && j < height;)
    {
        if (grid[i][j].isNode == false)
        {
            if (i + 1 >= width)
            {
                if (j + 1 >= height)
                    break;

                i = 0;
                ++j;
                continue;
            }
            else
            {
                ++i;
                continue;
            }
        }

        printf("%d %d ", i, j);
        int tmp = i + 1;
        while (tmp < width)
        {
            if (grid[tmp][j].isNode == false)
            {
                ++tmp;
                continue;
            }
            printf("%d %d ", tmp, j);
            break;
        }
        if (tmp >= width)
            printf("-1 -1 ");

        tmp = j + 1;
        while (tmp < height)
        {
            if (grid[i][tmp].isNode == false)
            {
                ++tmp;
                continue;
            }

            printf("%d %d\n", i, tmp);
            break;
        }

        if (tmp >= height)
            printf("-1 -1\n");

        // Next Node
        if (i + 1 >= width)
        {
            if (j + 1 >= height)
                break;

            i = 0;
            ++j;
        }
        else
        {
            ++i;
        }
    }

    return 0;
}