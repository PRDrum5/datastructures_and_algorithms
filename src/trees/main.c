#include "bfsearch.h"
#include "bst.h"
#include "trees.h"
#include <stdio.h>

int traverse_tree_examples(void) {
    int_tree_node_t *root = new_tree_node(17, NULL);
    root->left = new_tree_node(23, root);
    root->right = new_tree_node(3, root);

    root->left->left = new_tree_node(5, root->left);
    root->left->right = new_tree_node(4, root->left);

    root->right->left = new_tree_node(18, root->right);
    root->right->right = new_tree_node(21, root->right);

    visit_preorder_tranversal(root);
    visit_postorder_tranversal(root);
    visit_inorder_tranversal(root);

    free_tree(root);

    return 0;
}

int dfs_example(void) {
    int_tree_node_t *root = new_tree_node(17, NULL);
    root->left = new_tree_node(23, root);
    root->right = new_tree_node(3, root);

    root->left->left = new_tree_node(5, root->left);
    root->left->right = new_tree_node(4, root->left);

    root->right->left = new_tree_node(18, root->right);
    root->right->right = new_tree_node(21, root->right);

    bool found = false;
    int status = depth_search(root, 21, &found);
    printf("found? %d\n", found);

    free_tree(root);
    return 0;
}

int compare_trees_example(void) {
    int_tree_node_t *root = new_tree_node(17, NULL);
    root->left = new_tree_node(23, root);
    root->right = new_tree_node(3, root);

    root->left->left = new_tree_node(5, root->left);
    root->left->right = new_tree_node(4, root->left);

    root->right->left = new_tree_node(18, root->right);
    root->right->right = new_tree_node(21, root->right);

    int_tree_node_t *second_tree = new_tree_node(17, NULL);
    second_tree->left = new_tree_node(23, root);
    second_tree->right = new_tree_node(3, root);

    second_tree->left->left = new_tree_node(5, root->left);
    second_tree->left->right = new_tree_node(4, root->left);

    second_tree->right->left = new_tree_node(18, root->right);
    second_tree->right->right = new_tree_node(21, root->right);

    bool identical_trees = compare_trees(root, second_tree);

    printf("Trees are identical? %d\n", identical_trees);

    free_tree(root);
    free_tree(second_tree);

    return 0;
}

int create_bst_example(void) {
    int_tree_node_t *root = new_tree_node(20, NULL);
    insert_to_bst(root, 15);
    insert_to_bst(root, 25);
    insert_to_bst(root, 14);
    insert_to_bst(root, 5);
    insert_to_bst(root, 13);
    insert_to_bst(root, 14);
    insert_to_bst(root, 16);
    insert_to_bst(root, 16);
    insert_to_bst(root, 17);
    visit_inorder_tranversal(root);

    free_tree(root);

    return 0;
}

int search_bst_example(void) {
    int_tree_node_t *root = new_tree_node(17, NULL);
    insert_to_bst(root, 10);
    insert_to_bst(root, 50);

    insert_to_bst(root, 5);
    insert_to_bst(root, 16);

    insert_to_bst(root, 25);
    insert_to_bst(root, 51);

    const int needle = 51;
    int_tree_node_t *found_node = NULL;
    search_bst(root, needle, &found_node);

    if (found_node != NULL) {
        printf("Needle was found with value: %d\n", found_node->value);
    } else {
        printf("Needle was not found\n");
    }

    free_tree(root);

    return 0;
}

int delete_from_bst_example(void) {
    int_tree_node_t *root = new_tree_node(17, NULL);
    insert_to_bst(root, 10);
    insert_to_bst(root, 50);

    insert_to_bst(root, 5);
    insert_to_bst(root, 7);
    insert_to_bst(root, 16);
    insert_to_bst(root, 20);

    insert_to_bst(root, 25);
    insert_to_bst(root, 55);
    insert_to_bst(root, 52);

    visit_preorder_tranversal(root);
    visit_postorder_tranversal(root);

    const int needle = 17;
    int_tree_node_t *found_node = NULL;
    search_bst(root, needle, &found_node);

    if (found_node != NULL) {
        printf("Needle was found with value: %d\n", found_node->value);
    } else {
        printf("Needle was not found\n");
    }

    printf("lhs: %d\n", root->left->value);
    printf("rhs: %d\n", root->right->value);

    delete_from_bst(&root, needle);

    found_node = NULL;
    search_bst(root, needle, &found_node);
    if (found_node != NULL) {
        printf("Needle was found with value: %d\n", found_node->value);
    } else {
        printf("Needle was deleted\n");
    }

    visit_preorder_tranversal(root);
    visit_postorder_tranversal(root);

    free_tree(root);

    return 0;
}

int main(void) {
    traverse_tree_examples();
    dfs_example();
    compare_trees_example();
    create_bst_example();
    search_bst_example();
    delete_from_bst_example();
    return 0;
}
