#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t read;
    size_t write;
    size_t capacity;
    size_t length;
} ring_buffer_t;

ring_buffer_t *new_ring_buffer(const size_t capacity);
void delete_ring_buffer(ring_buffer_t *buffer);
int get(ring_buffer_t const *const buffer, const size_t idx, int *const value);
int enqueue(ring_buffer_t *const buffer, const int value);
int dequeue(ring_buffer_t *const buffer, int *const value);

#endif // RING_BUFFER_H
