#include "slide_line.h"

/**
* left_slide - slides and merges an array of integers
* @line: Pointer to an array of integers containing size elements
* @size: Number of elements in @line
*
* Return: 1 upon success, or 0 upon failure
*/
int left_slide(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
	return (1);
}

/**
* right_slide - slides and merges an array of integers
* @line: Pointer to an array of integers containing size elements
* @size: Number of elements in @line
*
* Return: 1 upon success, or 0 upon failure
*/
int right_slide(int *line, size_t size)
{
	size_t i, j;

	for (i = size - 1; (int)i >= 0; i--)
	{
		if (line[i] == 0)
		{
			for (j = i - 1; (int)j >= 0; j--)
			{
				if (line[j] != 0)
				{
					line[i] = line[j];
					line[j] = 0;
					break;
				}
			}
		}
	}
	return (1);
}

/**
* slide_line - slides and merges an array of integers
* @line: Pointer to an array of integers containing size elements
* @size: Number of elements in @line
* @direction: Direction to slide and merge the integers
*
* Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == 0)
	{
		left_slide(line, size);
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] * 2;
				line[i + 1] = 0;
			}
		}
		left_slide(line, size);
	}
	else if (direction == 1)
	{
		right_slide(line, size);
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] * 2;
				line[i - 1] = 0;
			}
		}
		right_slide(line, size);
	}
	return (1);
}
