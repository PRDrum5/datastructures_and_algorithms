#include "linked_list.h"

#include <stdio.h>

int main(void) {
    int value_0 = 0;
    linked_list_t *list = new_linked_list(value_0);
    if (list == NULL) {
        return 1;
    }
    printf("list->head->value: %d\n", list->head->value);
    printf("list->length: %d\n", list->length);

    int value_1 = 1;
    if (append(list, value_1) != 0) {
        printf("`append()` to Linked List failed\n");
        return 1;
    }
    printf("list->length: %d\n", list->length);

    int value_2 = 2;
    if (prepend(list, value_2) != 0) {
        printf("`prepend()` to Linked List failed\n");
        return 1;
    }
    printf("list->length: %d\n", list->length);
    printf("list->head->value: %d\n", list->head->value);

    int index = 0;
    int get_val = 99;
    if (get(list, index, &get_val) == 0) {
        printf("Invalid index: %d\n", index);
    } else {
        printf("Item: %d at Index: %d\n", get_val, index);
    }

    free_linked_list(list);

    return 0;
}

/*
int main(void) {
    int value = 5;
    int_node_t *list = get_linked_list(value);
    if (list == NULL) {
        return 1;
    }

    int prepend_value = 10;
    if (prepend(&list, prepend_value) != 0) {
        return 1;
    }

    int append_value = 1;
    if (append(list, append_value) != 0) {
        return 1;
    }

    printf("%d\n", list->value);
    printf("%d\n", list->next->value);
    printf("%d\n", list->next->next->value);

    printf("Linked List Length: %d\n", get_length(list));

    int found_value;
    int idx = 2;
    if (get(list, idx, &found_value) != 0) {
        printf("`get()` failed\n");
        return 1;
    } else {
        printf("Found value at %d: %d\n", idx, found_value);
    }

    idx = 1;
    if (insert_at(&list, 42, idx) != 0) {
        printf("`insert_at()` failed\n");
        return 1;
    }

    int drop_val = 1;
    if (remove_value(&list, drop_val) == 0) {
        printf("Value not removed or not found\n");
    } else {
        printf("%d\n", list->value);
        printf("%d\n", list->next->value);
        printf("%d\n", list->next->next->value);
    }

    int val = 99;
    idx = 1;
    if (remove_at(&list, idx, &val) != 0) {
        printf("`remove_at()` failed\n");
    } else {
        printf("Extracted value: %d\n", val);
        printf("%d\n", list->value);
        printf("%d\n", list->next->value);
    }

    free_linked_list(list);

    return 0;
}
*/
