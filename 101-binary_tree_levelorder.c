#include "binary_trees.h"

/*functions protypes*/
void enqueue(Queue_t *queue, binary_tree_t *treeNode);
binary_tree_t *dequeue(Queue_t *queue);
void freeQueue(Queue_t *queue);
/**
 * binary_tree_levelorder - traverse the tree in post order
 * @tree: the root of the tree
 * @func: a func that will be fired on the data of each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	Queue_t *queue = NULL;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;
	queue = (Queue_t *)malloc(sizeof(Queue_t));
	queue->front = queue->rear = NULL;

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
		current = (binary_tree_t *)queue->front->treeNode;
		dequeue(queue);

		if (current)
		{
			func(current->n);
			enqueue(queue, current->left);
			enqueue(queue, current->right);
		}
	}
	freeQueue(queue);
}

/**
 * enqueue - add new node the end of queue
 * @queue: pointer to queue
 * @treeNode: integer value
 */
void enqueue(Queue_t *queue, binary_tree_t *treeNode)
{
	struct QueueNode *newNode;

	newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
	if (newNode == NULL)
		return;
	newNode->treeNode = treeNode;
	newNode->next = NULL;

	if (queue->rear == NULL)
	{
		queue->front = queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/**
 * dequeue - delete queue node from top
 * @queue: pointer to queue
 * Return: node pointer
 */
binary_tree_t *dequeue(Queue_t *queue)
{
	struct QueueNode *tempNode;
	binary_tree_t *treeNode;

	if (queue->front == NULL)
		return (NULL);

	tempNode = queue->front;
	treeNode = tempNode->treeNode;

	queue->front = queue->front->next;
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(tempNode);
	return (treeNode);
}

/**
 * freeQueue - free queue by call dequeue
 * @queue: pointer to queue
 */
void freeQueue(Queue_t *queue)
{
	struct QueueNode *tempNode;

	while (queue->front != NULL)
	{
		tempNode = queue->front;
		queue->front = queue->front->next;
		free(tempNode);
	}
	free(queue);
}
