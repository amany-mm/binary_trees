#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the tree to the left
 * @tree: root node
 * Return: the new parent
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (!tree || !tree->right)
		return (tree);
	parent = tree->right;
	tree->right = parent->left;
	if (tree->right != NULL)
	{
		tree->right->parent = tree;
	}
	parent->left = tree;
	parent->parent = tree->parent;
	tree->parent = parent;

	return (parent);
}
