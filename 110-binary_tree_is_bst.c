#include "binary_trees.h"

/**
 * is_bst_valid - Recursive function that checks if a binary tree is a valid.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum value allowed for current node.
 * @max: Maximum value allowed for current node.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
*/

int is_bst_valid(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_valid(tree->left, min, tree->n - 1) &&
	is_bst_valid(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - That checks if a binary tree is a valid.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_valid(tree, INT_MIN, INT_MAX));
}
