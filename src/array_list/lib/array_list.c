#include "array_list.h"
#include <stdlib.h>
#include <string.h>

array_list_t *new_array_list(const size_t capacity) {
    array_list_t *array = (array_list_t *)malloc(sizeof(array_list_t));

    if (array != NULL) {
        array->length = 0;
        array->capacity = capacity;

        array->head = (int *)malloc(sizeof(int) * capacity);
        if (array->head == NULL) {
            // Free the array_list_t struct we allocated earlier
            free(array);
            array = NULL;
        }
    }

    return array;
}

void delete_array_list(array_list_t *array) {
    if (array != NULL) {
        if (array->head != NULL) {
            free(array->head);
        }
        free(array);
    }
    return;
}

int push(array_list_t *const array, const int value) {
    int status = 1;

    if ((array != NULL) && (array->head != NULL)) {
        if (array->length == array->capacity) {
            // Extend array
            size_t new_capacity = array->capacity * 2u;

            int *new_list = (int *)malloc(sizeof(int) * new_capacity);
            memcpy(new_list, array->head, sizeof(int) * array->capacity);

            int *old_list = array->head;
            array->head = new_list;
            array->capacity = new_capacity;
            free(old_list);
        }

        array->head[array->length] = value;
        array->length++;
        status = 0;
    }

    return status;
}

int pop(array_list_t *const array, int *const value) {
    int status = 1;

    if ((array != NULL) && (array->head != NULL)) {
        if (array->length != 0) {
            *value = array->head[array->length];
            array->length--;
            status = 0;
        }
    }

    return status;
}

int get(array_list_t const *const array, size_t idx, int *const value) {
    int status = 1;
    if ((array != NULL) && (array->head != NULL)) {
        if (array->length > idx) {
            *value = array->head[idx];
            status = 0;
        }
    }
    return status;
}
