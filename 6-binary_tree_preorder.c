#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * Return: None
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/**
	 * 1. Visit root node
	 * 2. Visit all the nodes in the left subtree
	 * 3. Visit all the nodes in the right subtree
	 */

	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);

		binary_tree_preorder(tree->right, func);

	}

}
