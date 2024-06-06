#include "binary_trees.h"

avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new_node, int new_val);

/**
 * avl_insert - Function that inserts a value into an AVL tree
 * @tree: The type **pointer to the root node of the AVL tree to insert into
 * @value: The value to store in the node to be inserted
 *
 * Return: New node, NULL otherwise
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	insert(tree, *tree, &new_node, value);
	return (new_node);
}

/**
 * insert - Function that does node value instertion in a AVL
 * @tree: The type **pointer of root node of the AVL tree struct
 * @parent: The parent node of struct AVL
 * @new_node: The type **pointer left or right insertion
 * @new_val: The insertion value of the AVL
 *
 * Return: Pointer to new root, NULL otherwise
 */
avl_t *insert(avl_t **tree, avl_t *parent, avl_t **new_node, int new_val)
{
	int bal_val;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, new_val));

	if ((*tree)->n > new_val)
	{
		(*tree)->left = insert(&(*tree)->left, *tree, new_node,
				new_val);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < new_val)
	{
		(*tree)->right = insert(&(*tree)->right, *tree, new_node,
				new_val);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bal_val = binary_tree_balance(*tree);
	if (bal_val > 1 && (*tree)->left->n > new_val)
		*tree = binary_tree_rotate_right(*tree);

	else if (bal_val > 1 && (*tree)->left->n < new_val)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_val < -1 && (*tree)->right->n < new_val)
		*tree = binary_tree_rotate_left(*tree);

	else if (bal_val < -1 && (*tree)->right->n > new_val)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
