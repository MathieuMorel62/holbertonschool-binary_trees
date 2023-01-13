#include "binary_trees.h"

/**
 * array_to_bst - that builds a Binary Search Tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure.
*/

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = 0;
	size_t index;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
		bst_insert(&root, array[index]);

	return (root);
}
