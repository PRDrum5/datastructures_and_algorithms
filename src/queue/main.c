#include "queue.h"

#include <stdio.h>

int main(void) {
    queue_t *q = new_queue();

    int value = 0;
    if (enqueue(q, value) != 0) {
        printf("Enqueue error\n");
    } else {
        printf("Queue Length: %d\n", q->length);
    }

    if (enqueue(q, ++value) != 0) {
        printf("Enqueue error\n");
    } else {
        printf("Queue Length: %d\n", q->length);
    }

    printf("q->head->value: %d\n", q->head->value);
    printf("q->head->next->value: %d\n", q->head->next->value);

    int head_value = 99;
    if (peek(q, &head_value) != 0) {
        printf("Error in `peek()`\n");
    }
    printf("value: %d\tLength: %d\n", head_value, q->length);

    if (dequeue(q, &head_value) != 0) {
        printf("Error in `dequeue()`\n");
    }
    printf("value: %d\tLength: %d\n", head_value, q->length);

    delete_queue(q);

    return 0;
}
