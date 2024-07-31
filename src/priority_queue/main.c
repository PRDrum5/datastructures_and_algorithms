#include "priority_queue.h"

#include <stdio.h>

int main(void) {
    printf("Priority Queue\n");

    array_list_t *priority_queue = new_priority_queue(4);
    add(priority_queue, 10);

    int value = 99;
    get_min_heap(priority_queue, &value);
    printf("min value: %d\n", value);

    add(priority_queue, 22);
    get_min_heap(priority_queue, &value);
    printf("min value: %d\n", value);

    add(priority_queue, 9);
    get_min_heap(priority_queue, &value);
    printf("min value: %d\n", value);

    add(priority_queue, 40);
    get_min_heap(priority_queue, &value);
    printf("min value: %d\n", value);

    return 0;
}
