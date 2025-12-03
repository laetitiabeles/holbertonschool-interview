#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - count nodes in a binary tree
 * @tree: pointer to root
 * Return: size_t number of nodes
 */
static size_t binary_tree_size(const heap_t *tree)
{
    if (!tree)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * get_node_by_index - get node at given 1-based index in level-order
 * @root: pointer to root
 * @index: 1-based index
 * Return: pointer to node or NULL
 */
static heap_t *get_node_by_index(heap_t *root, size_t index)
{
    size_t path = 0, bit;

    if (!root || index == 0)
        return (NULL);

    /* find highest bit position (msb) */
    path = index;
    /* remove msb (the root) by shifting until 1 remains */
    bit = 0;
    while (path > 1)
    {
        path >>= 1;
        bit++;
    }

    /* traverse from root using remaining bits of index */
    while (bit-- > 0)
    {
        if (index & (1 << bit))
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
        if (!root)
            return (NULL);
    }
    return (root);
}

/**
 * heapify_down - restore max-heap property from a node downwards
 * @node: node to heapify
 */
static void heapify_down(heap_t *node)
{
    heap_t *largest;
    int tmp;

    while (node)
    {
        largest = node;
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;
        if (largest == node)
            break;
        tmp = node->n;
        node->n = largest->n;
        largest->n = tmp;
        node = largest;
    }
}

/**
 * heap_extract - extracts the root value of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *r, *last, *parent;
    size_t size;
    int value;

    if (!root || !*root)
        return (0);

    r = *root;
    value = r->n;

    size = binary_tree_size(r);
    if (size == 1)
    {
        free(r);
        *root = NULL;
        return (value);
    }

    /* find last node (index = size) */
    last = get_node_by_index(r, size);
    if (!last)
        return (0);

    /* move last node's value to root */
    r->n = last->n;

    parent = last->parent;
    if (parent->left == last)
        parent->left = NULL;
    else if (parent->right == last)
        parent->right = NULL;

    free(last);

    /* restore heap property starting from root */
    heapify_down(r);

    return (value);
}
