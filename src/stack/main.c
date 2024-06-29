#include "stack.h"

#include <stdio.h>

int main(void) {
    int value = 1;
    stack_t *stk = new_stack(value);

    printf("Stack length: %d\n", stk->length);

    if (push(stk, value) != 0) {
        printf("Push to stack errored...\n");
        return 1;
    }
    printf("Stack length: %d\n", stk->length);

    int peek_value = 99;
    if (peek(stk, &peek_value) != 0) {
        printf("Error with `peek` function\n");
        return 1;
    }
    printf("Stack peek: %d\n", peek_value);
    printf("Stack length: %d\n", stk->length);

    value = 10;
    if (push(stk, value) != 0) {
        printf("Push to stack errored...\n");
        return 1;
    }

    if (peek(stk, &peek_value) != 0) {
        printf("Error with `peek` function\n");
        return 1;
    }
    printf("Stack peek: %d\n", peek_value);
    printf("Stack length: %d\n", stk->length);

    int pop_value = -1;
    if (pop(stk, &pop_value) != 1) {
        printf("Nothing to pop off stack\n");
    } else {
        printf("Stack Pop: %d\n", pop_value);
    }
    printf("Stack length: %d\n", stk->length);

    if (peek(stk, &peek_value) != 0) {
        printf("Error with `peek` function\n");
        return 1;
    }
    printf("Stack peek: %d\n", peek_value);
    printf("Stack length: %d\n", stk->length);

    if (pop(stk, &pop_value) != 1) {
        printf("Nothing to pop off stack\n");
    } else {
        printf("Stack Pop: %d\n", pop_value);
    }
    printf("Stack length: %d\n", stk->length);

    int len = delete_stack(stk);
    if (len != 0) {
        printf("Stack wasn't deleted fully...\n");
    }
    printf("Stack length: %d\n", len);

    return 0;
}
