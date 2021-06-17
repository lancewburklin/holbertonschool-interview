#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Merge sort algolrithim
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
**/

void merge_sort(int *array, size_t size)
{
	int *array2;

	if (size < 2)
		return;
	array2 = malloc(sizeof(int) * size);
	recur_merge_sort(array, array2, 0, size - 1);
	free(array2);
}

/**
 * recur_merge_sort - Recursive merge call
 * @array: Array to use
 * @array2: Second array
 * @left: Left side of array
 * @right: Right side of array
*/

void recur_merge_sort(int *array, int *array2, size_t left, size_t right)
{
	size_t mid = (left + (right - left - 1) / 2);

	if (left < right)
	{
		recur_merge_sort(array, array2, left, mid);
		recur_merge_sort(array, array2, mid + 1, right);
		if (left - right != 0)
			merge(array, array2, left, mid, right);
	}
}

/**
 * merge - Merge two arrays
 * @array: Array to merge
 * @array2: Second array
 * @l: Left side
 * @m: Middle
 * @r: right end point
*/

void merge(int *array, int *array2, size_t l, size_t m, size_t r)
{
	size_t i, j = 0, k = l, n1  = m - l + 1, n2 = r - m;

	printf("Merging...\n[left]: ");
	print_sub_array(array, l, m);
	printf("[right]: ");
	print_sub_array(array, m, r);
	for (i = 0; i < n1; i++)
		array2[i] = array[l + i];
	for (j = i; j - i < n2; j++)
		array2[j] = array[m + 1 + (j - i)];
	j = i, i = 0;
	while (i < n1 && j - n1 < n2)
	{
		if (array2[i] <= array2[j])
		{
			array[k] = array2[i];
			i++;
		}
		else
		{
			array[k] = array2[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = array2[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = array2[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_sub_array(array, l, r);
}

/**
 * print_sub_array - Print a parital array
 * @array: Array to print
 * @start: Starting point
 * @end: Ending point
*/

void print_sub_array(int *array, size_t start, size_t end)
{
	size_t count = start;

	while (count < end)
	{
		if (count != start)
			printf(", ");
		printf("%d", array[count]);
		count++;
	}
	printf("\n");
}
