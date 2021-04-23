#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * heap_sort - Sort a heap array
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Void
 */

void heap_sort(int *array, size_t size)
{
	size_t i = size;
	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (i > 0)
	{
		heapify(array, i, 0, size);
		temp = array[0];
		array[0] = array[i - 1];
		array[i - 1] = temp;
		print_array(array, size);
		i--;
	}
}

/**
 * heapify - Heapify an array
 * @array: Array to sort
 * @size: Size of the last item to check
 * @node: Current node
 * @t: Actual size of array, for printing
 *
 * Return: Node at the end
 */

size_t heapify(int *array, size_t size, size_t node, size_t t)
{
	size_t left = node;
	size_t right = node;
	int temp;

	if (node == size)
		return (node);
	if ((2 * node + 1) < size)
	{
		left = heapify(array, size, (2 * node) + 1, t);
	}
	if ((2 * node + 2) < size)
	{
		right = heapify(array, size, (2 * node) + 2, t);
	}
	if (array[node] < array[right] || array[node] < array[left])
	{
		if (array[left] > array[right])
		{
			temp = array[left];
			array[left] = array[node];
			array[node] = temp;
			print_array(array, t);
			heapify(array, size, left, t);
		}
		else if (array[right] >= array[left])
		{
			temp = array[right];
			array[right] = array[node];
			array[node] = temp;
			print_array(array, t);
			heapify(array, size, right, t);
		}
	}
	return (node);
}
