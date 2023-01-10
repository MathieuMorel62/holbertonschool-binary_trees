#include "binary_trees.h"

/**
 * binary_tree_nodes - that counts the 
 * nodes with at least 1 child in a binary tree
 * @tree: is a pointer to the root node 
 * of the tree to count the number of nodes
 * Return: 0 
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
        return (0);
    
    if (tree->left == NULL && tree->right == NULL)
		return (0);

	else
	    return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}
