#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @node: is a pointer to the node to find the sibling
 * Return: 0 if tree is NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

    if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
