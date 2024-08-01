/*
 * This implements a MinHeap Priority Queue for int values using the ArrayList
 * structure
 * */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "array_list.h"
#include <stddef.h>

array_list_t *new_priority_queue(const size_t capacity);
void delete_priority_queue(array_list_t *queue);
int add(array_list_t *queue, const int value);
int poll(array_list_t *queue, int *const value);
int get_min_heap(array_list_t const *const queue, int *value);

#endif // PRIORITY_QUEUE_H
