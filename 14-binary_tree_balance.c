#include "binary_trees.h"

/**
 * getHeight - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: binary tree height, If tree is NULL return 0.
 **/
int getHeight(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = getHeight(tree->left);
	right_height = getHeight(tree->right);

	return ((left_height > right_height) ?
		(left_height + 1) : (right_height + 1));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: the balance factor of a binary tree, If tree is NULL return 0.
 **/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (getHeight(tree->left) - getHeight(tree->right));
}
