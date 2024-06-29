#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static int_stack_frame_t *new_frame(const int value) {
    int_stack_frame_t *frame =
        (int_stack_frame_t *)malloc(sizeof(int_stack_frame_t));

    if (frame != NULL) {
        frame->value = value;
        frame->prev = NULL;
    }

    return frame;
}

stack_t *new_stack(const int value) {
    stack_t *s = malloc(sizeof(stack_t));

    s->head = new_frame(value);

    if (s->head != NULL) {
        s->length = 1;
    } else {
        s->length = 0;
    }

    return s;
}

int delete_stack(stack_t *s) {
    int_stack_frame_t *frame = s->head;
    int_stack_frame_t *p_frame = NULL;

    while (frame != NULL) {
        p_frame = frame->prev;
        free(frame);
        frame = p_frame;
        s->length--;
    }

    int length = s->length;
    free(s);
    return length;
}

int peek(stack_t *s, int *value) {
    int status = 1;

    if (s != NULL) {
        if (s->length > 0) {
            status = 0;
            *value = s->head->value;
        }
    }

    return status;
}

int push(stack_t *s, const int value) {
    int status = 1;

    if (s != NULL) {
        status = 0;

        int_stack_frame_t *frame = malloc(sizeof(int_stack_frame_t));
        frame->value = value;
        frame->prev = NULL;
        s->length++;

        if (s->head != NULL) {
            frame->prev = s->head;
            s->head = frame;
        } else {
            s->head = frame;
        }
    }

    return status;
}

int pop(stack_t *s, int *value) {
    int items_popped = 0;

    if (s->head != NULL) {
        items_popped = 1;

        *value = s->head->value;

        int_stack_frame_t *prev_head = s->head->prev;

        free(s->head);

        s->head = prev_head;

        s->length--;
    }

    return items_popped;
}
