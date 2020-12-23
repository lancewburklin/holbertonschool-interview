#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
* binary_tree_node - Creates a binary tree node
* @parent: Parent of the node
* @value: Value to insert into node
* Return: NULL on fail, the node on success
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->n = value;
    new_node->parent = parent;
    return (new_node);
}
