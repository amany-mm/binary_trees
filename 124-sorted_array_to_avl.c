#include "binary_trees.h"

void avl_sa(avl_t **root, int *array, size_t min, size_t max);

/**
 * sorted_array_to_avl - Function that builds an AVL tree from an array
 * @array: Pointer to first element of array to be converted
 * @size: The size of node
 *
 * Return: New node, NULL if otherwise
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t mid;

	if (!array)
		return (NULL);

	mid = (size - 1) / 2;
	avl_tree = binary_tree_node(NULL, array[mid]);

	avl_sa(&avl_tree, array, -1, mid);
	avl_sa(&avl_tree, array, mid, size);

	return (avl_tree);
}

/**
 * avl_sa - Function that builds an AVL tree from an array
 * @root: Double pointer to root subtree
 * @array: Pointer to first element of array to be converted
 * @min: The lower bound index
 * @max: The upper bound index
 *
 * Return: None
 */
void avl_sa(avl_t **root, int *array, size_t min, size_t max)
{
	avl_t *new_node = NULL;
	size_t mid;

	if (max - min > 1)
	{
		mid = (max - min) / 2 + min;

		new_node = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = new_node;

		else if (array[mid] < (*root)->n)
			(*root)->left = new_node;

		avl_sa(&new_node, array, min, mid);
		avl_sa(&new_node, array, mid, max);
	}
}
