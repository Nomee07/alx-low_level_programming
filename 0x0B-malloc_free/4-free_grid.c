#include <stdlib.h>
#include "main.h"

/**
 * free_grid - Frees the memory allocated for 2D
 * @grid: The grid to be be freed
 * @height: Height of the grid
 * Return: Nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;


	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
		free(grid[i]);
	}

	free(grid);
}
