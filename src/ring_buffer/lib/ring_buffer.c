#include "ring_buffer.h"
#include <stdlib.h>

ring_buffer_t *new_ring_buffer(const size_t capacity) {
    ring_buffer_t *buffer = (ring_buffer_t *)malloc(sizeof(ring_buffer_t));
    if (buffer != NULL) {
        buffer->data = (int *)malloc(capacity * sizeof(int));
        if (buffer->data != NULL) {
            buffer->capacity = capacity;
            buffer->length = 0;
            buffer->read = 0;
            buffer->write = 0;
        } else {
            free(buffer);
            buffer = NULL;
        }
    }
    return buffer;
}

void delete_ring_buffer(ring_buffer_t *buffer) {
    if (buffer->data != NULL) {
        free(buffer->data);
    }

    free(buffer);
}

int enqueue(ring_buffer_t *const buffer, const int value) {
    int status = 1;

    if ((buffer != NULL) && (buffer->data != NULL)) {
        if (buffer->capacity <= buffer->length) {
            // Increase the capacity to hold more data
            int *new_buffer = (int *)malloc(2 * buffer->capacity * sizeof(int));
            int read_idx;

            // Copy old buffer into new buffer
            for (size_t i = 0; i < buffer->length; ++i) {
                read_idx = buffer->read % buffer->length;
                new_buffer[i] = buffer->data[read_idx];
                buffer->read++;
            }

            free(buffer->data);
            buffer->data = new_buffer;
            buffer->read = 0;
            buffer->write = buffer->length;
            buffer->capacity = 2 * buffer->capacity;
        }

        buffer->data[buffer->write] = value;
        buffer->length++;
        buffer->write = (buffer->write + 1) % buffer->capacity;
        status = 0;
    }

    return status;
}

int dequeue(ring_buffer_t *const buffer, int *const value) {
    int status = 1;

    if ((buffer != NULL) && (buffer->data != NULL) && (buffer->length > 0)) {

        *value = buffer->data[buffer->read];
        buffer->length--;
        buffer->read = (buffer->read + 1) % buffer->capacity;
        status = 0;
    }

    return status;
}

int get(ring_buffer_t const *const buffer, const size_t idx, int *const value) {
    int status = 1;
    if ((buffer != NULL) && (buffer->data != NULL) && (buffer->length > 0) &&
        (idx < buffer->length)) {
        size_t read_idx = (buffer->read + idx) % buffer->capacity;
        *value = buffer->data[read_idx];
        status = 0;
    }
    return status;
}
