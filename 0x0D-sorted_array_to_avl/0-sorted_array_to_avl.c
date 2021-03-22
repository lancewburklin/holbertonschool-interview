#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Take an array and turn it into an avl tree
 * @array: Array to convert
 * @size: Size of the array
 *
 * Return: Root of the tree, or null on failure
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *answer;
	int mid = (size - 1) / 2;

	if (array == NULL)
		return (NULL);
	answer = malloc(sizeof(avl_t));
	if (answer == NULL)
		return (NULL);
	answer->n = array[mid];
	answer->parent = NULL;
	answer->left = to_avl_recursive(answer, array, 0, mid - 1);
	answer->right = to_avl_recursive(answer, array, mid + 1, size - 1);
	if (binary_tree_size(answer) != size)
		return (NULL);
	return (answer);
}

/**
 * binary_tree_size - Finds the size of a binary tree
 * @tree: The tree to find the size of
 *
 * Return: The size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t num = 1;

	if (tree == NULL)
		return (0);

	num += binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (num);
}

/**
 * to_avl_recursive - Recursively build avl tree
 * @parent: Parent node
 * @array: Array to convert to avl tree
 * @start: Start point of avl tree
 * @end: End point for avl tree
 *
 * Return: Tree head on success, NULL for malloc fail
*/

avl_t *to_avl_recursive(avl_t *parent, int *array, int start, int end)
{
	int mid = (start + end) / 2;
	avl_t *node;

	if (start > end)
		return (NULL);
	node = malloc(sizeof(avl_t));
	node->n = array[mid];
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->left = to_avl_recursive(node, array, start, mid - 1);
	node->right = to_avl_recursive(node, array, mid + 1, end);

	return (node);
}
