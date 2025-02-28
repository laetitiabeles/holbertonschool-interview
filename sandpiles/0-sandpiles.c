#include <stdio.h>

void print_grid(int grid[3][3]);
void topple_sandpiles(int grid[3][3]);

/**
* print_grid - prints a 3x3 grid
* @grid: 3x3 grid to be printed
*/
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
* sandpiles_sum - add two sandpiles and stabilize the result
* @grid1: Left 3x3 grid
* @grid2: Right 3x3 grid
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable = 0;

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
			grid1[i][j] += grid2[i][j];
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (grid1[i][j] > 3)
				unstable = 1;
		}
	}

	if (unstable)
		print_grid(grid1);

	while (unstable)
	{
		topple_sandpiles(grid1);
		unstable = 0;
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				if (grid1[i][j] > 3)
					unstable = 1;
			}
		}
		if (unstable)
			print_grid(grid1);
	}
}

/**
* topple_sandpiles - Topple the sandpiles to stabilize the grid
* @grid: The grid to be stabilized
*/
void topple_sandpiles(int grid[3][3])
{
	int i, j, temp_grid[3][3];

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
			temp_grid[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			if (temp_grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j]++;
				if (i < 2)
					grid[i + 1][j]++;
				if (j > 0)
					grid[i][j - 1]++;
				if (j < 2)
					grid[i][j + 1]++;
			}
		}
	}
}
