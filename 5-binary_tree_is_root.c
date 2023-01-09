#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * Description: 'returns a binary tree'
 * Return: size_t
 * @node: binary_tree node
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (1);

	else
		return (0);
}