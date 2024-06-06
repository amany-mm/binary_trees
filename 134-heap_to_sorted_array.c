#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Func that converts BMH to sorted array of integers
 * @heap: Pointer to root node of heap to convert
 * @size: The address to store size of array
 *
 * Return: Generated array, NULL otherwise
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL, i;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (!array)
		return (NULL);

	for (i = 0; heap; i++)
		array[i] = heap_extract(&heap);

	return (array);
}

/**
 * tree_size - Function that measures sum of heights of a binary tree
 * @tree: Pointer to root node of tree to measure height
 * Return: Height, 0 otherwise
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + tree_size(tree->left);

	if (tree->right)
		r_height = 1 + tree_size(tree->right);

	return (l_height + r_height);
}
