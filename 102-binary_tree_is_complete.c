#include "binary_trees.h"

int binary_tree_level(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);

	return (binary_tree_level(tree, 0, size));
}

/**
 * binary_tree_level - Function that checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: The node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_level(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_level(tree->left, 2 * index + 1, size) &&
			binary_tree_level(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: Size of tree, 0 if otherwise
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
			binary_tree_size(tree->right) + 1);
}
