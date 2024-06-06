#include "binary_trees.h"

/**
 * binary_tree_size - measures the the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: the size of a binary tree, If tree is NULL return 0
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));

}
