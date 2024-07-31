#include "bst.h"
#include "trees.h"
#include <stddef.h>
#include <stdlib.h>

enum Node_Children { NO_CHILDREN, ONE_CHILD, TWO_CHILDREN };

int search_bst(int_tree_node_t *const root, int const needle,
    int_tree_node_t **found_node) {
    int status = 1;

    if (root != NULL) {
        if (needle == root->value) {
            status = 0;
            *found_node = root;
        } else if (needle < root->value) {
            status = search_bst(root->left, needle, found_node);
        } else if (needle > root->value) {
            status = search_bst(root->right, needle, found_node);
        } else {
            status = 0;
            *found_node = NULL;
        }
    }
    return status;
}

int insert_to_bst(int_tree_node_t *tree, int const value) {
    int status = 1;

    if (tree != NULL) {
        status = 0;
        if (value <= tree->value) {
            if (tree->left != NULL) {
                status = insert_to_bst(tree->left, value);
            } else {
                tree->left = new_tree_node(value, tree);
            }
        } else if (value > tree->value) {
            if (tree->right != NULL) {
                status = insert_to_bst(tree->right, value);
            } else {
                tree->right = new_tree_node(value, tree);
            }
        }
    }

    return status;
}

static enum Node_Children count_children(int_tree_node_t *node) {
    enum Node_Children children = TWO_CHILDREN;

    if ((node->left == NULL) && (node->right == NULL)) {
        children = NO_CHILDREN;
    } else if ((node->left == NULL) || (node->right == NULL)) {
        children = ONE_CHILD;
    }

    return children;
}

static bool node_is_left_of_parent(
    int_tree_node_t *parent, int_tree_node_t *child) {
    bool state = false;
    if (parent->left == child) {
        state = true;
    }

    return state;
}

static int_tree_node_t *largest_node_in_tree(int_tree_node_t *tree) {
    int_tree_node_t *big_node = NULL;

    if (tree != NULL) {
        if (tree->right != NULL) {
            big_node = largest_node_in_tree(tree->right);
        } else {
            big_node = tree;
        }
    }

    return big_node;
}

static void delete_bst_node(int_tree_node_t *node) {
    if (node_is_left_of_parent(node->parent, node)) {
        node->parent->left = NULL;
    } else {
        node->parent->right = NULL;
    }
    free(node);
}

static void delete_bst_node_with_child(int_tree_node_t *node) {
    int_tree_node_t *child_node;
    if (node->left == NULL) {
        child_node = node->right;
    } else {
        child_node = node->left;
    }

    if (node_is_left_of_parent(node->parent, node)) {
        node->parent->left = child_node;
    } else {
        node->parent->right = child_node;
    }
    free(node);
}

static int delete_bst_node_with_two_children(
    int_tree_node_t *node, int_tree_node_t **root) {

    int status = 0;
    int_tree_node_t *biggest_node = largest_node_in_tree(node);

    switch (count_children(biggest_node)) {
    case NO_CHILDREN:
        biggest_node->parent = node->parent;
        biggest_node->right = NULL;
        biggest_node->left = node->left;
        biggest_node->left->parent = biggest_node;
        break;

    case ONE_CHILD:
        biggest_node->parent = node->parent;
        biggest_node->right = biggest_node->left;
        biggest_node->left = node->left;
        biggest_node->left->parent = biggest_node;
        break;

    default:
        status = 1;
        break;
    }

    if (status == 0) {
        // Make sure the parent of the node, now points to the correct child.
        if (node->parent != NULL) {
            if (node_is_left_of_parent(node->parent, node)) {
                node->parent->left = biggest_node;
            } else {
                node->parent->right = biggest_node;
            }
        } else {
            *root = biggest_node;
        }

        // Now delete the node
        free(node);
    }

    return status;
}

int delete_from_bst(int_tree_node_t **p_tree, int const value) {
    int status = 1;
    int_tree_node_t *tree = *p_tree;

    if ((p_tree != NULL) && (tree != NULL)) {
        int_tree_node_t *search_node = NULL;

        search_bst(tree, value, &search_node);

        if (search_node != NULL) {
            switch (count_children(search_node)) {
            case NO_CHILDREN:
                delete_bst_node(search_node);
                break;

            case ONE_CHILD:
                delete_bst_node_with_child(search_node);
                break;

            case TWO_CHILDREN:
                delete_bst_node_with_two_children(search_node, p_tree);
                break;

            default:
                status = 1;
                break;
            }
        }
    }

    return status;
}
