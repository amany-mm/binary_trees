#include "binary_trees.h"
#include "0-binary_tree_node.c"

void pre_order(heap_t *tree, heap_t **node, size_t height);
void make_heap(heap_t *root);
size_t tree_height(const heap_t *tree);

/**
 * heap_extract - Function that extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of heap
 * Return: Value, 0 otherwise
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *mbh, *new_node;

	if (!root || !*root)
		return (0);

	mbh = *root;
	value = mbh->n;
	if (!mbh->left && !mbh->right)
	{
		*root = NULL;
		free(mbh);
		return (value);
	}

	pre_order(mbh, &new_node, tree_height(mbh));

	mbh->n = new_node->n;
	if (new_node->parent->right)
		new_node->parent->right = NULL;
	else
		new_node->parent->left = NULL;

	free(new_node);
	make_heap(mbh);
	*root = mbh;
	return (value);
}

/**
 * pre_order - Function that visits a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @node: The last note in preorder traverse
 * @height: The tree height
 *
 * Return: None
 */
void pre_order(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;

	height--;

	pre_order(tree->left, node, height);
	pre_order(tree->right, node, height);
}

/**
 * make_heap - Function that heapifies max binary heap
 * @root: Pointer to binary heap
 * Return: None
 */
void make_heap(heap_t *root)
{
	heap_t *tmp_l, *tmp_r;
	int value;

	if (!root)
		return;

	tmp_l = root;

	while (1)
	{
		if (!tmp_l->left)
			break;

		if (!tmp_l->right)
			tmp_r = tmp_l->left;
		else
		{
			if (tmp_l->left->n > tmp_l->right->n)
				tmp_r = tmp_l->left;
			else
				tmp_r = tmp_l->right;
		}
		if (tmp_l->n > tmp_r->n)
			break;

		value = tmp_l->n;
		tmp_l->n = tmp_r->n;
		tmp_r->n = value;
		tmp_l = tmp_r;
	}
}

/**
 * tree_height - Function that measures the height of a binary tree
 * @tree: Pointer to root node of tree to measure height
 * Return: Height, 0 otherwise
 */
size_t tree_height(const heap_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + tree_height(tree->left);

	if (tree->right)
		r_height = 1 + tree_height(tree->right);

	if (l_height > r_height)
		return (l_height);

	return (r_height);
}
