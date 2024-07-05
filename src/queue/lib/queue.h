#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct int_q_node_t {
    int value;
    struct int_q_node_t *next;
} int_q_node_t;

typedef struct {
    int_q_node_t *head;
    int_q_node_t *tail;
    int length;
} queue_t;

queue_t *new_queue(void);
int delete_queue(queue_t *q);
int enqueue(queue_t *q, int value);
int dequeue(queue_t *q, int *value);
int peek(queue_t *q, int *value);

#endif // QUEUE_H
