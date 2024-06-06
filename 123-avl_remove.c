#include "binary_trees.h"

bst_t *remove_(bst_t *root, int value);
int remove_type(bst_t *root);
int successor(bst_t *node);
void avl_bal(avl_t **tree);

/**
 * avl_remove - Function that removes a node from a AVL tree
 * @root: The root of binary tree
 * @value: The node with value to remove
 *
 * Return: The updated tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *) remove_((bst_t *) root, value);

	if (avl_root == NULL)
		return (NULL);

	avl_bal(&avl_root);
	return (avl_root);
}

/**
 * remove_ - Function that removes a node from a BST tree
 * @root: The root of binary tree
 * @value: The node with value to remove
 *
 * Return: The updated tree
 */
bst_t *remove_(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		remove_(root->left, value);

	else if (value > root->n)
		remove_(root->right, value);

	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			remove_(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * remove_type - Function that removes a node depending of its children
 * @root: The root node to remove
 * Return: Value, 0 if otherwise
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;

			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;

			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * successor - Function to get the next successor in binary tree
 * @node: The tree to check
 * Return: Min value
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 * avl_bal - Function that measures balance factor of a AVL
 * @tree: The tree to go through
 * Return: Balance factor
 */
void avl_bal(avl_t **tree)
{
	int bal_val;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	avl_bal(&(*tree)->left);
	avl_bal(&(*tree)->right);

	bal_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (bal_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);

	else if (bal_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
