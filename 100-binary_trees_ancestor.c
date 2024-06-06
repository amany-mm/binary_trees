#include "binary_trees.h"

/**
 * binary_tree_depth - the depth of the tree
 * @tree: the root node
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	binary_tree_t *cur_parent;
	size_t depth = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);
	cur_parent = tree->parent;
	while (cur_parent)
	{
		depth++;
		cur_parent = cur_parent->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: Lowest common ancestor or Null if not found
 */
binary_tree_t *
binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *min_node, *max_node, *save_min;
	size_t depth_first, depth_second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (depth_first >= depth_second)
	{
		max_node = (binary_tree_t *) first;
		min_node = (binary_tree_t *) second;
	} else
	{
		max_node = (binary_tree_t *) second;
		min_node = (binary_tree_t *) first;
	}
	save_min = max_node;

	while (min_node && max_node)
	{
		if (min_node == max_node)
			return (min_node);
		if (max_node->parent == NULL)
		{
			min_node = min_node->parent;
			max_node = save_min;
		} else
		{
			max_node = max_node->parent;
		}
	}

	return (NULL);
}
