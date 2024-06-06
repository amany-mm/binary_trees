#include "binary_trees.h"

/**
 * array_to_avl - Function that builds an AVL tree from an array
 * @array: The array to create from
 * @size: Size of the array
 *
 * Return: Pointer to root, NULL otherwise
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *root_node = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&root_node, array[i]);

	return (root_node);
}
