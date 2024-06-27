#include "linked_list.h"

#include <stdio.h>

int main(void) {
    int value_0 = 0;
    linked_list_t *list = new_linked_list(value_0);
    if (list == NULL) {
        return 1;
    }

    int value_1 = 1;
    if (append(list, value_1) != 0) {
        printf("`append()` to Linked List failed\n");
        return 1;
    }

    int value_2 = 2;
    if (prepend(list, value_2) != 0) {
        printf("`prepend()` to Linked List failed\n");
        return 1;
    }

    printf("Before insert, length now: %d\n", list->length);
    int insert_idx = 2;
    int insert_value = 42;
    if (insert_at(list, insert_value, insert_idx) != 0) {
        printf("`insert_at` failed\n");
    }
    printf("inserted at 2, length now: %d\n", list->length);

    int_node_t *node = list->head;
    printf("Full Linked List\n");
    for (int i = 0; i < list->length; i++) {
        printf("Index: %d\tValue: %d\n", i, node->value);
        node = node->next;
    }

    int index = 0;
    int get_val = -1;
    if (get(list, index, &get_val) == 0) {
        printf("Invalid index: %d\n", index);
    } else {
        printf("Value at index {%d} is: {%d}\n", index, get_val);
    }

    int remove_val = 42;
    printf("Remove the value %d\n", remove_val);
    if (remove_value(list, remove_val) != 1) {
        printf("`remove_value()` failed\n");
    }

    node = list->head;
    printf("Full Linked List\n");
    for (int i = 0; i < list->length; i++) {
        printf("Index: %d\tValue: %d\n", i, node->value);
        node = node->next;
    }

    index = 0;
    remove_val = -1;
    if (remove_at(list, index, &remove_val) != 0) {
        printf("`remove_at()` failed\n");
    } else {
        printf("Removed item: %d from Index: %d\n", remove_val, index);
    }

    node = list->head;
    printf("Full Linked List\n");
    for (int i = 0; i < list->length; i++) {
        printf("Index: %d\tValue: %d\n", i, node->value);
        node = node->next;
    }

    free_linked_list(list);

    return 0;
}
