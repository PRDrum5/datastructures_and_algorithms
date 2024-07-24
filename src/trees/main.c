#include "bfsearch.h"
#include "trees.h"
#include <stdio.h>

int main(void) {
    int_tree_node_t *root = new_tree_node(17);
    root->left = new_tree_node(23);
    root->right = new_tree_node(3);

    root->left->left = new_tree_node(5);
    root->left->right = new_tree_node(4);

    root->right->left = new_tree_node(18);
    root->right->right = new_tree_node(21);

    visit_preorder_tranversal(root);
    visit_postorder_tranversal(root);
    visit_inorder_tranversal(root);

    bool found = false;
    int status = depth_search(root, 21, &found);
    printf("found? %d\n", found);

    free_tree(root);

    return 0;
}
