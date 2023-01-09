#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *newNodeRight = malloc(sizeof(binary_tree_t));

	if (parent == NULL || newNodeRight == NULL)
		return (NULL);

	newNodeRight->n = value;
	newNodeRight->parent = parent;
	newNodeRight->left = NULL;

	if (parent->right != NULL)
	{
		newNodeRight->right = parent->right;
		parent->right->parent = newNodeRight;
	}
	else
		newNodeRight->right = NULL;
		parent->right = newNodeRight;
	
	return (newNodeRight);
}
