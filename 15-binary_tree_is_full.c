#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full;
 * a tree in which every node has either zero children or two children.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: If the tree is full, otherwise return 0.
 **/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));

	return (0);
}
