#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sandpiles.h"


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

/**
  * get_sum - Finds intitial unbalanced sum
  * @grid1: Grid1
  * @grid2: Grid2
*/

static void get_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int x = 0;

	while (i < 3)
	{
		x = 0;
		while (x < 3)
		{
			grid1[i][x] += grid2[i][x];
			x++;
		}
		i++;
	}
}

/**
  * sandpiles_sum - Get the sum of 2 sandpiles
  * @grid1: First frid
  * @grid2: Second grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int x = 0;
	int test = 1;

	get_sum(grid1, grid2);
	memcpy(grid2, grid1, 9 * sizeof(int));
	while (test == 1)
	{
		i = 0;
		test = 0;
		memcpy(grid1, grid2, 9 * sizeof(int));
		while (i < 3)
		{
			x = 0;
			while (x < 3)
			{
				if (grid1[i][x] > 3)
				{
					test = 1;
					grid2[i][x] -= 4;
					if (i - 1 != -1)
						grid2[i - 1][x] += 1;
					if (i + 1 != 3)
						grid2[i + 1][x] += 1;
					if (x - 1 != -1)
						grid2[i][x - 1] += 1;
					if (x + 1 != 3)
						grid2[i][x + 1] += 1;
				}
				x++;
			}
			i++;
		}
		if (test != 0)
		{
			printf("=\n");
			print_grid(grid1);
		}
	}
}
