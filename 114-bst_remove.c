#include "binary_trees.h"
#include <stdio.h>
bst_t *find_min(bst_t *root);
/**
 * bst_remove - remove a node from a BST
 * @root: root of the tree
 * @value: value to be removed
 * Return: root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min, *temp;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			if (root->parent != NULL)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
				if (temp != NULL)
					temp->parent = root->parent;
			}
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			if (root->parent != NULL)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
				if (temp != NULL)
					temp->parent = root->parent;
			}
			free(root);
			return (temp);
		}
		else
		{
			min = find_min(root->right);
			root->n = min->n;
			root->right = bst_remove(root->right, min->n);
		}
	}
	return (root);
}
/**
 * find_min - find minimum in a tree.
 * @root: the root of the tree
 * Return: pointer to a node that has the min value
 */
bst_t *find_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
