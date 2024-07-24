#ifndef TREE_H
#define TREE_H

typedef struct int_tree_node_t {
    int value;
    struct int_tree_node_t *left;
    struct int_tree_node_t *right;
} int_tree_node_t;

int_tree_node_t *new_tree_node(const int value);
void free_tree(int_tree_node_t *node);

void visit_preorder_tranversal(int_tree_node_t const *const root);
void visit_postorder_tranversal(int_tree_node_t const *const root);
void visit_inorder_tranversal(int_tree_node_t const *const root);

#endif // TREE_H
