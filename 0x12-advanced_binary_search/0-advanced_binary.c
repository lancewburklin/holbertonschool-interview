#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - Advanced binary search
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to find
 *
 * Return: First location of the value
 */

int advanced_binary(int *array, size_t size, int value)
{
	int loc;

	if (array == NULL)
		return (-1);
	loc = binary_recursive(array, value, 0, size - 1);
	return (loc);
}

/**
 * binary_recursive - Recursive search
 * @array: Array to search
 * @value: Value to search for
 * @start: Start location
 * @end: End location
 *
 * Return: First found location
 */

int binary_recursive(int *array, int value, size_t start, size_t end)
{
	size_t i;
	int mid;

	if (start > end)
		return (-1);
	i = start;
	printf("Searching in array: ");
	printf("%d", array[i]);
	i++;
	while (i < end + 1)
	{
		printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
	mid = ((start + end) / 2);
	if (array[mid] == value && array[mid - 1] < value)
		return (mid);
	if (value <= array[mid])
		return (binary_recursive(array, value, start, mid));
	if (value > array[mid])
		return (binary_recursive(array, value, mid + 1, end));
	return (-1);
}
