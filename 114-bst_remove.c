#include "binary_trees.h"

/**
 * minValueNode - function that finds the node with the minimum value
 * in a BST
 * @node: pointer to the root node of the tree
 *
 * Return: pointer to the node with the minimum value
 */

bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - function that removes a node from a BST
 * @root: pointer to the root node of the tree
 * @value: value to be removed
 *
 * Return: pointer to the new root node
 */

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}
		bst_t *temp = minValueNode(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
