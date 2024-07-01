#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>

typedef struct {
    int *head;
    size_t length;
    size_t capacity;
} array_list_t;

array_list_t *new_array_list(const size_t capacity);
void delete_array_list(array_list_t *array);
int get(array_list_t const *const array, size_t idx, int *const value);
int push(array_list_t *const array, const int value);
int pop(array_list_t *const array, int *const value);

#endif // ARRAY_LIST_H
