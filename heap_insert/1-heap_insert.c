#include "binary_trees.h"

/**
 * length - find the length of the binary tree.
 * @root: the root node.
 * Return: the length of the binary tree.
 */
int length(heap_t **root)
{
	if (!root || !*root)
		return (0);

	return (length(&((*root)->left)) + length(&((*root)->right)) + 1);
}


/**
 * heap_insert - insert a node into the max heap.
 * @root: the root node.
 * @value: the value to insert.
 * Return: the node inserted or null.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node = NULL;
	int len = (length(root) - 1) / 2;

	if (!root)
		return (NULL);

	node = malloc(sizeof(heap_t));

	if (!node)
		return (NULL);

	node = binary_tree_node(*root, value);

	if (!*root)
	{
		*root = node;
		return (node);
	}
	if (len == 0)
		return (NULL);
	if (len > 0 && len % 2)
		(*root) = (*root)->left;
	if (len > 0 && !(len % 2))
		*root = (*root)->right;
	node->(*root) = *root;
	if (!(*root)->left)
		(*root)->left = node;
	else
		(*root)->right = node;
	return (node);
}
