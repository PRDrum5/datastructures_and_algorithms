#include "priority_queue.h"
#include "array_list.h"

array_list_t *new_priority_queue(const size_t capacity) {
    return new_array_list(capacity);
}

static size_t get_left_child_index(size_t current_index) {
    return 2 * current_index + 1;
}

static size_t get_right_child_index(size_t current_index) {
    return 2 * current_index + 2;
}

static size_t get_parent_index(size_t current_index) {
    return (current_index - 1) / 2; // Makes use of floor division
}

static void bubble_up(array_list_t *queue, size_t index) {
    int tmp = 0;
    while (index != 0) {
        size_t parent_index = get_parent_index(index);
        if (queue->head[parent_index] > queue->head[index]) {
            // swap parent and child.
            tmp = queue->head[parent_index];
            queue->head[parent_index] = queue->head[index];
            queue->head[index] = tmp;
            index = parent_index;
        } else {
            index = 0;
        }
    }
}

int add(array_list_t *queue, const int value) {
    int status = 1;
    size_t index = queue->length;

    if (push(queue, value) == 0) {
        bubble_up(queue, index);
    }

    return status;
}

int get_min_heap(array_list_t const *const queue, int *value) {
    int status = 1;
    if (queue != NULL) {
        if (queue->length > 0) {
            status = 0;
            *value = *queue->head;
        }
    }

    return status;
}
