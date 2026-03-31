#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int index;
    char top;
    char bottom;
} Group;

int compare_groups(const void *a, const void *b)
{
    Group *ga = (Group *)a;
    Group *gb = (Group *)b;
    return ga->index - gb->index;
}

int main()
{
    int W;
    int H;
    scanf("%d%d", &W, &H);
    fgetc(stdin);

    // dynamic array sizing
    size_t arr_size = (W / 3) + 1;
    Group *arr = malloc(arr_size * sizeof(Group));
    if (arr == NULL)
    {
        printf("Array allocation failed\n");
        return 1;
    }

    for (int i = 0; i <= H; i++)
    {
        char line[1025] = "";
        // first loop, store the characters
        if (i == 0)
        {
            for (int j = 0; j < arr_size; ++j)
            {
                arr[j].index = j;
                scanf(" %c", &arr[j].top);
            }
            // force next loop
            continue;
        }
        else if (i == H)
        {
            for (int j = 0; j < arr_size; ++j)
            {
                char ch;
                scanf(" %c", &ch);
                arr[j].bottom = ch;
            }
            continue;
        }

        scanf("%[^\n]", line);
        fgetc(stdin);

        for (int j = 1; j < W; j += 3)
        {
            if (line[j] == '-')
            {
                Group tmp = arr[j / 3];
                arr[j / 3] = arr[(j / 3) + 1];
                arr[(j / 3) + 1] = tmp;
            }
        }
    }

    qsort(arr, arr_size, sizeof(Group), compare_groups);

    for (int i = 0; i < arr_size; ++i)
    {
        printf("%c%c", arr[i].top, arr[i].bottom);
        printf("\n");
    }

    free(arr);
    return 0;
}