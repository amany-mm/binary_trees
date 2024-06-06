#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree
 *
 * @array: pointer to the first element of the array
 * @size: number of element in the array
 * Return: pointer to the root node of the AVL tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	if (!array)
		return (NULL);

	root = NULL;
	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}

