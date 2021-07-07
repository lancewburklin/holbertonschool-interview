#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Radix sorting an array
 * @array: Array to sort
 * @size: Size of the array
**/
void radix_sort(int *array, size_t size)
{
	int *temp, *num, max, place, max2, n;
	size_t i;

	if (size == 0 || size == 1)
		return;
	max = getLargest(array, size);
	for (place = 1; max / place > 0; place *= 10)
	{
		temp = malloc(sizeof(int) * (size + 1));
		if (temp == NULL)
			return;
		max2 = (array[0] / place) % 10;
		for (i = 1; i < size; i++)
		{
			if (((array[i] / place) % 10) > max2)
				max2 = array[i];
		}
		num = malloc(sizeof(int) * (max2 + 1));
		if (num == NULL)
			return;
		for (n = 0; n < max2; n++)
			num[n] = 0;
		for (i = 0; i < size; i++)
			num[(array[i] / place) % 10]++;
		for (i = 1; i < 10; i++)
			num[i] += num[i - 1];
		for (n = size - 1; n >= 0; n--)
		{
			temp[num[(array[n] / place) % 10] - 1] = array[n];
			num[(array[n] / place) % 10]--;
		}
		for (i = 0; i < size; i++)
			array[i] = temp[i];
		print_array(array, size);
		free(temp);
		free(num);
	}
}

/**
 * getLargest - Get the largest int in array
 * @array: Array to sort
 * @size: Size of the array
 * Return: Largest in
**/

int getLargest(int *array, size_t size)
{
	int large;
	size_t i;

	i = 0;
	large = array[0];
	while (i < size)
	{
		if (array[i] > large)
			large = array[i];
		i++;
	}
	return (large);
}
