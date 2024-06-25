#include "linked_list.h"

#include <stdio.h>

int main(void) {
    int value = 5;
    int_node *list = get_linked_list(value);
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
