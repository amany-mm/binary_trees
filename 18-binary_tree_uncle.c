#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: root node
 * Return: node is NULL, return NULL uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL)
		return (NULL);

	if (node->parent && node->parent->parent)
	{
		uncle = node->parent->parent->left;
		if (uncle == node->parent)
			uncle = node->parent->parent->right;
		return (uncle);
	}
	return (NULL);
}
