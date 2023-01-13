#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * tree_is_complete - checks if tree is complete
 * @tree: pointer to the tree root
 * @index: node index
 * @complete_nodes: number of nodes in a tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int tree_is_complete(const binary_tree_t *tree, int index, int complete_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= complete_nodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * index) + 1, complete_nodes) &&
		tree_is_complete(tree->right, (2 * index) + 2, complete_nodes));
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t complete_nodes;

	if (tree == NULL)
		return (0);

	complete_nodes = binary_tree_size(tree);

	return (tree_is_complete(tree, 0, complete_nodes));
}
