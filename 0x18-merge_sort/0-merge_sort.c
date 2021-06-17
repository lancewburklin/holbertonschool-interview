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
	recur_merge_sort(array, 0, size - 1);
}

/**
 * recur_merge_sort - Recursive merge call
 * @array: Array to use
 * @left: Left side of array
 * @right: Right side of array
*/

void recur_merge_sort(int *array, size_t left, size_t right)
{
	size_t mid = (left + (right - left - 1) / 2);

	if (left < right)
	{
		recur_merge_sort(array, left, mid);
		recur_merge_sort(array, mid + 1, right);
		if (left - right != 0)
			merge(array, left, mid, right);
	}
}

/**
 * merge - Merge two arrays
 * @array: Array to merge
 * @l: Left side
 * @m: Middle
 * @r: right end point
*/

void merge(int *array, size_t l, size_t m, size_t r)
{
	size_t i, j = 0, k = l, n1  = m - l + 1, n2 = r - m;
	int L[n1], R[n2];

	printf("Merging...\n[left]: ");
	print_sub_array(array, l, m);
	printf("[right]: ");
	print_sub_array(array, m, r);
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (i = 0; i < n2; i++)
		R[i] = array[m + 1 + i];
	i = 0;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
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
