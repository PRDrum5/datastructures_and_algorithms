#ifndef BST_H
#define BST_H

#include "trees.h"

int search_bst(int_tree_node_t *const root, int const needle,
    int_tree_node_t **found_node);
int insert_to_bst(int_tree_node_t *tree, int const value);
int delete_from_bst(int_tree_node_t **p_tree, int const value);

#endif // BST_H
