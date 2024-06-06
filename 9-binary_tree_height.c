#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: Height of tree, or 0 if tree is MULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_child = 0, r_child = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l_child = 1 + binary_tree_height(tree->left);

	if (tree->right)
		r_child = 1 + binary_tree_height(tree->right);

	return (l_child > r_child ? l_child : r_child);

}
