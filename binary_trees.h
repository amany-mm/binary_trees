#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Basic Binary Tree */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;


/**
 * struct QueueNode - Structure for a node in the queue
 * @treeNode: Pointer to a binary tree node
 * @next: Pointer to the next node in the queue
 *
 * Description: Structure representing a node in the queue
 */
struct QueueNode
{
	binary_tree_t *treeNode;
	struct QueueNode *next;
};

/**
 * struct Queue_t - Structure for a queue
 * @front: Pointer to the front of the queue
 * @rear: Pointer to the rear of the queue
 *
 * Description: Structure representing a queue
 */
typedef struct Queue_t
{
	struct QueueNode *front;
	struct QueueNode *rear;
} Queue_t;



/* Print function */
void binary_tree_print(const binary_tree_t *);

/* New node, Insert left, Insert right, Delete */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);

/* Is leaf, Is root */
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);

/* Pre-order traversal, In-order traversal, Post-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* Height, Depth, Size */
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);

/* Leaves, Nodes */
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);

/* Balance factor, Is full, Is perfect */
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/* Sibling, Uncle, Lowest common ancestor */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);

/* Level-order traversal, Is complete */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);

/* Rotate left, Rotate right */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* Is BST, BST - Insert,  BST - Array to BST, BST - Search, BST - Remove */
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

/* Is AVL, AVL-Insert, AVL-Array to AVL, AVL-Remove, AVL-From sorted array */
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

/*
* Is Binary heap, Heap-Insert, Heap-Array to Binary Heap, Heap-Insert,
* Heap-Array to Binary Heap, Heap-Extract, Heap-Sort
*/
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

#endif /* BINARY_TREES_H */
