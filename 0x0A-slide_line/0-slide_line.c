#include <stdlib.h>
#include <stdio.h>

#include "slide_line.h"

/**
 * slide_line - Slides a line to the left or right like 2048
 * @line: Line to slide
 * @size: Size of the line
 * @direction: Direction to slide the line
 *
 * Return: 1 for success, 0 for a failure
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0, x = 0;

	if (size == 1)
		return (1);
	if (direction == 0)
	{
		for (x = 1; x < size; x++, i++)
		{
			if (line[i] == line[x])
			{
				line[i] = line[i] * 2;
				line[x] = 0;
				if (line[i + 1] == 0)
					i++;
				x++;
			}
			else if (line[x] == 0)
			{
				while (line[x] == 0 && x < size)
				{
					x++;
					if (line[i] == line[x])
					{
						line[i] = line[i] * 2;
						line[x] = 0;
						i++;
						x = i;
						break;
					}
				}
				x = i + 1;
			}
		}
		merge(line, size, direction);
	}
	else if (direction == 1)
		return (slide_right(line, size, direction));
	else
		return (0);
	return (1);
}

/**
 * slide_right - Slides a line to the right like 2048
 * @line: Line to slide
 * @size: Size of the line
 * @direction: Direction to slide the line
 *
 * Return: 1
 */

int slide_right(int *line, size_t size, int direction)
{
	size_t i = size - 1;
	size_t x = size - 2;

	if (direction == 1)
	{
		for (;; x--, i--)
		{
			if (line[i] == line[x])
			{
				line[i] = line[i] * 2;
				line[x] = 0;
			}
			else if (line[x] == 0)
			{
				while (line[x] == 0)
				{
					if (x == 0)
						break;
					x--;
					if (line[i] == line[x])
					{
						line[i] = line[i] * 2;
						line[x] = 0;
						i--;
						x = i;
						break;
					}
				}
				x = i - 1;
			}
			if (x == 0)
				break;
		}
		merge(line, size, direction);
	}
	return (1);
}

/**
 * merge - Merges the line left or right
 * @line: Line to merge
 * @size: Size of the line
 * @direction: Direction to merge
 *
 * Return: 1
 */

int merge(int *line, size_t size, int direction)
{
	size_t i = 0, x = 1;

	if (direction == 0)
	{
		for (x = 0; x < size; i++, x++)
		{
			if (line[i] == 0)
			{
				while (line[x] == 0 && x < size)
				{
					x++;
				}
				printf("%d\n", line[x]);
				line[i] = line[x];
				line[x] = 0;
				if (x == size)
					break;
			}
		}
	}
	else
	{
		for (x = size - 1, i = size - 2; ; i--, x--)
		{
			if (line[x] == 0)
			{
				while (line[i] == 0)
				{
					if (i == 0)
						break;
					i--;
				}
				line[x] = line[i];
				line[i] = 0;
			}
			if (i == 0)
				break;
		}
	}
	return (1);
}
