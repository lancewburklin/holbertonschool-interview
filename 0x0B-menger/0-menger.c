#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * menger - Create a menger sponge
 * @level: Level of the sponge
 *
 * Return: VOID
**/

void menger(int level)
{
	int i, j, size, d;
	int depth = level;

	size = pow(3, depth);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			for (d = size / 3; d; d /= 3)
			{
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
					break;
			}
			printf(d ? " " : "#");
				}
				printf("\n");
			}
}
