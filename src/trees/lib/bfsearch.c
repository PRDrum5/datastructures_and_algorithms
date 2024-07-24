#include "bfsearch.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct queue_node_t {
    int_tree_node_t *current;
    struct queue_node_t *next;
} queue_node_t;

typedef struct bfs_queue_t {
    queue_node_t *head;
    queue_node_t *tail;
    int length;
} bfs_queue_t;

static bfs_queue_t *new_queue(void) {
    bfs_queue_t *queue = (bfs_queue_t *)malloc(sizeof(bfs_queue_t));

    queue->head = NULL;
    queue->tail = NULL;
    queue->length = 0;

    return queue;
}

static queue_node_t *new_node(int_tree_node_t *tree_node) {
    queue_node_t *node = (queue_node_t *)malloc(sizeof(queue_node_t));

    node->current = tree_node;
    node->next = NULL;

    return node;
}

static int delete_queue(bfs_queue_t *queue) {
    queue_node_t *node;
    queue_node_t *next_node;

    if (queue != NULL) {
        if (queue->head != NULL) {
            node = queue->head;

            while (node->next != NULL) {
                next_node = node->next;
                free(node);
                node = next_node;
                queue->length--;
            }

            free(node);
            queue->length--;
        }
    }

    int length = queue->length;
    free(queue);
    return length;
}

static int enqueue(bfs_queue_t *queue, int_tree_node_t *tree_node) {
    int status = 1;

    if (queue != NULL) {
        queue_node_t *node = new_node(tree_node);

        if (queue->head == NULL) {
            queue->head = node;
            queue->tail = node;
            queue->length = 1;
            status = 0;
        } else if (queue->tail != NULL) {
            queue->tail->next = node;
            queue->tail = node;
            queue->length++;
            status = 0;
        }
    }

    return status;
}

static int dequeue(bfs_queue_t *queue, int *value) {
    int status = 1;

    if (queue != NULL) {
        if (queue->length > 1) {
            queue_node_t *next_head = queue->head->next;
            *value = queue->head->current->value;

            free(queue->head);

            queue->head = next_head;
            queue->length--;
            status = 0;

        } else if (queue->length == 1) {
            *value = queue->head->current->value;

            free(queue->head);

            queue->head = NULL;
            queue->tail = NULL;
            queue->length = 0;
            status = 0;
        }
    }

    return status;
}

static int peek(bfs_queue_t const *const q, int *value) {
    int status = 1;
    if (q != NULL) {
        if (q->length > 0) {
            *value = q->head->current->value;
            status = 0;
        }
    }
    return status;
}

int depth_search(int_tree_node_t *const root, int const needle, bool *found) {
    int status = 1;
    int value = needle + 1;
    *found = false;
    bfs_queue_t *queue = new_queue();

    if (root != NULL) {
        if (enqueue(queue, root) == 0) {
            while (queue->length > 0) {

                // Add children to queue
                if (queue->head->current->left != NULL) {
                    if (enqueue(queue, queue->head->current->left) != 0) {
                        break;
                    }
                }
                if (queue->head->current->right != NULL) {
                    if (enqueue(queue, queue->head->current->right) != 0) {
                        break;
                    }
                }

                if (dequeue(queue, &value) != 0) {
                    break;
                }
                if (value == needle) {
                    *found = true;
                    break;
                }
            }
        }
    }

    delete_queue(queue);

    return status;
}
