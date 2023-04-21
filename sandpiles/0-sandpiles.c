#include "sandpiles.h"
#include <stdio.h>

/**
 * grid_status - Check the status of a grid
 * @grid1: a 3x3 grid
 * 
 * Return: 1 if a grid is stable, 0 otherwise
*/

int grid_status(int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid1[i][j] > 3)
                return 0; 
        }
    }

    /* At this point, the grid is stable :) */
    return 1;
}


/**
 * add_grids - Excecute the math operation: sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
*/

void add_grids(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
}

/**
 * print_grid - Print a grid in stdout
 * @grid1: 3x3 grid
*/

void print_grid(int grid1[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d", grid1[i][j]);
            if (j != 2)
                printf(" ");
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * 
 * Return: a 3x3 grid with the sum result
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int new_grid[3][3];

    /* Add the two grids */
    add_grids(grid1, grid2);

    /* Check status of the resulting grid: if isn't stable --> toppling */
    while (!grid_status(grid1))
    {
        int i, j;
        
        /* Print the current grid result that is saved in grid1 */
        printf("=\n");
        print_grid(grid1);

        /* Initialize the new grid */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
                new_grid[i][j] = 0;
        }

        /* Performe toppling if any value is > 3 */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (grid1[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if ((i - 1 >= 0) && (i - 1 < 3))
						new_grid[i - 1][j] += 1;
					if ((j - 1 >= 0) && (j - 1 < 3))
						new_grid[i][j - 1] += 1;
					if ((i + 1 >= 0) && (i + 1 < 3))
						new_grid[i + 1][j] += 1;
					if ((j + 1 >= 0) && (j + 1 < 3))
						new_grid[i][j + 1] += 1;
                }
            }
        }

        /* Performe the operation with the new grid */
        add_grids(grid1, new_grid);
    }
}
