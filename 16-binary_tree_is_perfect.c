#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance factor
 * of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if the input tree is NULL.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left) + 1;
	right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_is_perfect - Function that checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL, your function must return 0.
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree) == 0)
	{
		if ((binary_tree_height(tree->left) == 0)
		&& (binary_tree_height(tree->right) == 0))
			return (1);

		return (binary_tree_is_perfect(tree->left)
		&& binary_tree_is_perfect(tree->right));
	}
	return (0);
}
