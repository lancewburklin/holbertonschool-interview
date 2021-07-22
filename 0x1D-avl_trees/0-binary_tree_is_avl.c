#include "binary_trees.h"
#include "limits.h"

/**
 * binary_tree_is_avl - Determine if binary tree is AVL
 * @tree: Tree to check
 *
 * Return: 1 for true, 0 for false
*/

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_tree_recur(tree));
}

/**
 * avl_tree_recur - Recursive helper
 * @tree: Tree to check
 *
 * Return: 1 or 0
*/

int avl_tree_recur(const binary_tree_t *tree)
{
	int lHeight, rHeight;

	if (tree == NULL)
		return (1);
	lHeight = binary_tree_height(tree->left);
	rHeight = binary_tree_height(tree->right);
	if (abs(lHeight - rHeight) <= 1 &&
	avl_tree_recur(tree->left) &&
	avl_tree_recur(tree->right) &&
	BTS(tree, INT_MIN, INT_MAX))
		return (1);
	return (0);
}

/**
 * BTS - Check if BTS
 * @tree: Tree to check
 * @min: Min test
 * @max: Max test
 * Return: 1 or 0
*/

int BTS(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (BTS(tree->left, min, tree->n - 1) &&
	BTS(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Finds the height of a binary tree at a node
 * @tree: Tree to find the height of
 *
 * Return: The height
 */

int binary_tree_height(const binary_tree_t *tree)
{
	size_t num = 0;
	size_t num_right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left)
		num = 1 + binary_tree_height(tree->left);
	else
		num = 0;
	if (tree->right)
		num_right = 1 + binary_tree_height(tree->right);
	else
		num_right = 0;
	if (num > num_right)
		return (num);
	return (num_right);
}
