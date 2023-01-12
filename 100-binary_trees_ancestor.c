#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	/* Check if pointers are valid */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Check if first and second are the same node */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Assign first_parent and second_parent to the parent */
	first_parent = first->parent;
	second_parent = second->parent;

	/* Check if first is the parent of second */
	if (first == second_parent || !first_parent || (
		!first_parent->parent && second_parent))
		return (binary_trees_ancestor(first, second_parent));

	/* Check if first_parent is the parent of second */
	else if (first_parent == second || !second_parent || (
		!second_parent->parent && first_parent))
		return (binary_trees_ancestor(first_parent, second));

	/* Recursively call function with parents */
	return (binary_trees_ancestor(first_parent, second_parent));
}
