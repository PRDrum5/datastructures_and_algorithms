#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

typedef struct int_node_t {
    int value;
    struct int_node_t *next;
} int_node_t;

typedef struct {
    int_node_t *head;
    int length;
} linked_list_t;

linked_list_t *new_linked_list(const int value);
void free_linked_list(linked_list_t *list);
int get_length(linked_list_t const *const list);
int append(linked_list_t *list, const int value);
int prepend(linked_list_t *list, const int value);
int get(linked_list_t *list, const int index, int *value);
int insert_at(linked_list_t *list, const int value, const int index);
int remove_at(linked_list_t *list, const int index, int *value);
int remove_value(linked_list_t *list, const int value);

#endif // LINKED_LIST_H
