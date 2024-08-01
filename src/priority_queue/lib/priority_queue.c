#include "priority_queue.h"
#include "array_list.h"

array_list_t *new_priority_queue(const size_t capacity) {
    return new_array_list(capacity);
}

void delete_priority_queue(array_list_t *queue) {
    delete_array_list(queue);
    return;
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

static int bubble_up(array_list_t *queue, size_t index) {
    int status = 1;

    if ((is_initalized(queue)) && (index <= queue->length)) {
        status = 0;

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

    return status;
}

static int bubble_down(array_list_t *queue) {
    int status = 1;

    if ((is_initalized(queue)) && (queue->length > 0)) {
        size_t index = 0;
        int value = queue->head[index];
        size_t left_child_idx = get_left_child_index(index);
        size_t right_child_idx = get_right_child_index(index);

        int l_value;
        if (get(queue, left_child_idx, &l_value) != 0) {
            l_value = value;
        }

        int r_value;
        if (get(queue, right_child_idx, &r_value) != 0) {
            r_value = value;
        }

        while ((value > l_value) || (value > r_value)) {
            if (l_value < r_value) {
                // swap with left
                queue->head[index] = l_value;
                queue->head[left_child_idx] = value;
                index = left_child_idx;
            } else {
                // swap with right
                queue->head[index] = r_value;
                queue->head[right_child_idx] = value;
                index = right_child_idx;
            }

            value = queue->head[index];
            left_child_idx = get_left_child_index(index);
            right_child_idx = get_right_child_index(index);

            if (get(queue, left_child_idx, &l_value) != 0) {
                l_value = value;
            }

            if (get(queue, right_child_idx, &r_value) != 0) {
                r_value = value;
            }
        }

        status = 0;
    }

    return status;
}

int add(array_list_t *queue, const int value) {
    int status = 1;
    size_t index = queue->length;

    status = push(queue, value);
    if (status == 0) {
        status = bubble_up(queue, index);
    }

    return status;
}

int poll(array_list_t *queue, int *const value) {
    int status = 1;

    if ((is_initalized(queue)) && (queue->length > 0)) {
        *value = queue->head[0];
        queue->length--;
        status = 0;
        if (queue->length > 0) {
            queue->head[0] = queue->head[queue->length];
            status = bubble_down(queue);
        }
    }

    return status;
}

int get_min_heap(array_list_t const *const queue, int *const value) {
    int status = 1;
    if ((is_initalized(queue)) && (queue->length > 0)) {
        status = 0;
        *value = *queue->head;
    }

    return status;
}
