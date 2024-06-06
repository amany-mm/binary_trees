#include "binary_trees.h"

/**
 * binary_tree_height - height of a binary tree
 * @tree: pointer to tree node
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * get_size - the size of the tree
 * @tree: the root of the tree
 * @counter: number of nodes of the tree
 * Return: size of the tree
 */

size_t get_size(binary_tree_t *tree, size_t *counter)
{
	if (!tree)
		return (0);
	(*counter)++;
	get_size(tree->left, counter);
	get_size(tree->right, counter);
	return (*counter);
}

/**
 * binary_tree_size - the size of the tree
 * @tree: the root of the tree
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL)
		return (0);
	left_size = get_size(tree->left, &left_size);
	right_size = get_size(tree->right, &right_size);

	return (1 + right_size + left_size);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect;
 * in which every internal node has exactly two child nodes and
 * all the leaf nodes are at the same level.
 * @tree: root node
 * Return: 1 is_perfect otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hight_of_tree, size_of_tree, i, two_pow_h = 1;

	if (tree == NULL)
		return (0);

	hight_of_tree = binary_tree_height(tree);
	size_of_tree = binary_tree_size(tree);

	for (i = 0; i <= hight_of_tree; i++)
		two_pow_h *= 2;

	return (size_of_tree == two_pow_h - 1);
}
