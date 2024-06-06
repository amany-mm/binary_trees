#include "binary_trees.h"

/**
 * array_to_bst - convert an array to a BST
 * @array: the array
 * @size: size of the array
 * Return: a node to the root of the BST
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);
	return (root);
}
