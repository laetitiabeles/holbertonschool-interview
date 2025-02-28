#include "sandpiles.h"
#include <stdio.h>

int sandpile_is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0;
        }
    }

    return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int isStable;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    isStable = sandpile_is_stable(grid1);

    while (isStable != 1)
    {
        printf("=\n");
        print_grid(grid1);

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if (j - 1 >= 0)
                        grid1[i][j - 1] += 1;
                    if (j + 1 <= 2)
                        grid1[i][j + 1] += 1;
                    if (i - 1 >= 0)
                        grid1[i - 1][j] += 1;
                    if (i + 1 <= 2)
                        grid1[i + 1][j] += 1;
                }
            }
        }

        isStable = sandpile_is_stable(grid1);
    }
}
