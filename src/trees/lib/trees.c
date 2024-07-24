#include "trees.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int_tree_node_t *new_tree_node(const int value) {
    int_tree_node_t *node = (int_tree_node_t *)malloc(sizeof(int_tree_node_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void free_tree(int_tree_node_t *node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

static void visit_preorder(int_tree_node_t const *const node) {
    if (node != NULL) {
        printf("%d, ", node->value);
        visit_preorder(node->left);
        visit_preorder(node->right);
    }
}

static void visit_postorder(int_tree_node_t const *const node) {
    if (node != NULL) {
        visit_postorder(node->left);
        visit_postorder(node->right);
        printf("%d, ", node->value);
    }
}

static void visit_inorder(int_tree_node_t const *const node) {
    if (node != NULL) {
        visit_postorder(node->left);
        printf("%d, ", node->value);
        visit_postorder(node->right);
    }
}

void visit_preorder_tranversal(int_tree_node_t const *const root) {
    visit_preorder(root);
    printf("\n");
}

void visit_postorder_tranversal(int_tree_node_t const *const root) {
    visit_postorder(root);
    printf("\n");
}

void visit_inorder_tranversal(int_tree_node_t const *const root) {
    visit_inorder(root);
    printf("\n");
}
