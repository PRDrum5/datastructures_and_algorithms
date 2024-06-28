#include "queue.h"
#include <stdlib.h>

static int_q_node_t *new_q_node(const int value) {
    int_q_node_t *node = malloc(sizeof(int_q_node_t));
    node->next = NULL;
    node->value = value;

    return node;
}

queue_t *new_queue(const int value) {
    queue_t *q = malloc(sizeof(queue_t));
    int_q_node_t *node = new_q_node(value);

    q->head = node;
    q->tail = node;
    q->length = 1;

    return q;
}

int delete_queue(queue_t *q) {
    int_q_node_t *node;
    int_q_node_t *next_node;

    if (q->head != NULL) {
        node = q->head;

        while (node->next != NULL) {
            next_node = node->next;
            free(node);
            node = next_node;
            q->length--;
        }

        free(node);
        q->length--;
    }

    int length = q->length;

    free(q);

    return length;
}

int enqueue(queue_t *q, int value) {
    int status = 1;
    if (q != NULL) {
        int_q_node_t *node = new_q_node(value);

        if (q->head == NULL) {
            q->head = node;
            q->tail = node;
            q->length = 1;

            status = 0;
        } else if (q->tail != NULL) {
            q->tail->next = node;
            q->tail = node;
            q->length++;

            status = 0;
        }
    }
    return status;
}

int dequeue(queue_t *q, int *value) {
    int status = 1;

    if (q != NULL) {
        if (q->length > 1) {
            int_q_node_t *next_head = q->head->next;
            *value = q->head->value;

            free(q->head);

            q->head = next_head;

            q->length--;

            status = 0;
        } else if (q->length == 1) {
            *value = q->head->value;
            free(q->head);
            q->head = NULL;
            q->tail = NULL;
            q->length = 0;
            status = 0;
        }
    }

    return status;
}

int peek(queue_t *q, int *value) {
    int status = 1;

    if (q != NULL) {
        if (q->length > 0) {
            *value = q->head->value;
            status = 0;
        }
    }

    return status;
}
