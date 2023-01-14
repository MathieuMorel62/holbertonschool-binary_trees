#include "binary_trees.h"

/**
 * min_value_node - that finds the node with the minimum value in a BST
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the node with the minimum value
 */

bst_t *min_value_node(bst_t *root)
{
	bst_t *current = root;

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
	bst_t *temp, *parent;

	if (root == NULL)
		return (root);

	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = min_value_node(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
