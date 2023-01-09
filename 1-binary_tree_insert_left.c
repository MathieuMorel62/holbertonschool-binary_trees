#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNodeLeft;

	if (parent == NULL)
		return (NULL);

	newNodeLeft = malloc(sizeof(binary_tree_t));

	if (newNodeLeft == NULL)
		return (NULL);

	newNodeLeft->n = value;
	newNodeLeft->parent = parent;
	newNodeLeft->right = NULL;

	if (parent->left != NULL)
	{
		newNodeLeft->left = parent->left;
		parent->left->parent = newNodeLeft;
	}
	else
	{
		newNodeLeft->left = NULL;
	}
	parent->left = newNodeLeft;

	return (newNodeLeft);
}