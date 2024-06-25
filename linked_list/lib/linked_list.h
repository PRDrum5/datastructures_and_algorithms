#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct int_node {
    int value;
    struct int_node *next;
} int_node;

int_node *get_linked_list(int value);
void free_linked_list(int_node *node_start);
int get_length(int_node *node);
int get(int_node *node, int index, int *value);
int prepend(int_node **node_start, int value);
int append(int_node *node, int value);
int insert_at(int_node **node, int value, int index);
int remove_value(int_node **list_start, const int value);
int remove_at(int_node **list_start, const int index, int *value);

#endif // LINKED_LIST_H
