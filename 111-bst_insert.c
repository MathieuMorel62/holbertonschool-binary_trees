#include "binary_trees.h"

/**
 * bst_insert - That inserts a value in a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node_current, *new_node;

	if (tree != NULL)
	{
		node_current = *tree;

		if (node_current == NULL)
		{
			new_node = binary_tree_node(node_current, value);
			if (new_node == NULL)
				return (NULL);
			return (*tree = new_node);
		}
		if (value < node_current->n)
		{
			if (node_current->left != NULL)
				return (bst_insert(&node_current->left, value));

			new_node = binary_tree_node(node_current, value);

			if (new_node == NULL)
				return (NULL);
			return (node_current->left = new_node);
		}
		if (value > node_current->n)
		{
			if (node_current->right != NULL)
				return (bst_insert(&node_current->right, value));

			new_node = binary_tree_node(node_current, value);

			if (new_node == NULL)
				return (NULL);
			return (node_current->right = new_node);
		}
	}
	return (NULL);
}
