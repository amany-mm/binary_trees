#include "binary_trees.h"
/**
 * bst_search - search on a BST
 * @tree: the root of the tree
 * @value: value
 * Return: pointer to a node that has the value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree || tree->n == value)
		return ((bst_t *)tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
