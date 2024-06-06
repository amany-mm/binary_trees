#include "binary_trees.h"
#include <stdio.h>
/*prototypes*/
size_t get_size(binary_tree_t *tree, size_t *counter);
size_t binary_tree_size(const binary_tree_t *tree);
void binary_tree_to_array(const binary_tree_t *tree, size_t *tree_size,
						  int *tree_arr);
int binary_tree_is_avl_helper(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to tree node
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int *tree_arr;
	size_t tree_size, tmp_size, i;

	if (tree == NULL)
		return (0);
	tree_size = binary_tree_size(tree);
	tmp_size = tree_size - 1;
	tree_arr = malloc(sizeof(int) * tree_size);
	binary_tree_to_array(tree, &tmp_size, tree_arr);

	for (i = 0; i + 1 != tree_size; i++)
	{
		if (tree_arr[i] <= tree_arr[i + 1])
		{
			free(tree_arr);
			return (0);
		}
	}
	free(tree_arr);
	return (binary_tree_is_avl_helper(tree));
}

/**
 * binary_tree_is_avl_helper - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to tree node
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree)
{
	size_t height_left, height_right;
	int balance_factor;

	if (tree == NULL)
		return (1);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);
	balance_factor = (int)height_left - (int)height_right;

	if (balance_factor >= -1 && balance_factor <= 1 &&
		binary_tree_is_avl_helper(tree->left) &&
		binary_tree_is_avl_helper(tree->right))
		return (1);

	return (0);
}

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
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree pointer
 * @tree_size: tree size pointer
 * @tree_arr: tree_arr pointer
 */
void binary_tree_to_array(const binary_tree_t *tree, size_t *tree_size,
						  int *tree_arr)
{
	if (tree == NULL)
		return;

	binary_tree_to_array(tree->left, tree_size, tree_arr);
	tree_arr[*tree_size] = tree->n;
	*tree_size = *(tree_size) - 1;

	binary_tree_to_array(tree->right, tree_size, tree_arr);
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
