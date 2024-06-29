#ifndef STACK_H
#define STACK_H

typedef struct int_stack_frame_t {
    int value;
    struct int_stack_frame_t *prev;
} int_stack_frame_t;

typedef struct {
    int_stack_frame_t *head;
    int length;
} stack_t;

stack_t *new_stack(const int value);
int delete_stack(stack_t *s);
int peek(stack_t *s, int *value);
int push(stack_t *s, const int value);
int pop(stack_t *s, int *value);

#endif
