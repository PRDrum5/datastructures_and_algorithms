#include "stack.h"
#include <unity.h>

void test_push_stack(void) {
    const int value = 100;
    stack_t *s = new_stack(value);

    TEST_ASSERT_NOT_NULL(s);

    int peeked_value = -1;
    TEST_ASSERT_EQUAL(0, peek(s, &peeked_value));
    TEST_ASSERT_EQUAL(value, peeked_value);

    const int_stack_frame_t *first_stack_frame = s->head;

    const int new_value = 55;
    int status = push(s, new_value);

    TEST_ASSERT_EQUAL(2, s->length);
    TEST_ASSERT_NOT_NULL(s->head->prev);
    TEST_ASSERT_EQUAL(first_stack_frame, s->head->prev);

    TEST_ASSERT_EQUAL(0, peek(s, &peeked_value));
    TEST_ASSERT_EQUAL(new_value, peeked_value);

    TEST_ASSERT_EQUAL(0, delete_stack(s));
}

void test_pop_stack(void) {
    const int value = 100;
    stack_t *s = new_stack(value);

    TEST_ASSERT_NOT_NULL(s);

    const int new_value = 55;
    int status = push(s, new_value);
    TEST_ASSERT_EQUAL(0, status);

    int popped_val = -1;
    int n_pops = 0;
    n_pops = pop(s, &popped_val);
    TEST_ASSERT_EQUAL(1, n_pops);
    TEST_ASSERT_EQUAL(new_value, popped_val);
    TEST_ASSERT_EQUAL(1, s->length);

    int peeked_value = -1;
    TEST_ASSERT_EQUAL(0, peek(s, &peeked_value));
    TEST_ASSERT_EQUAL(value, peeked_value);

    n_pops = pop(s, &popped_val);
    TEST_ASSERT_EQUAL(1, n_pops);
    TEST_ASSERT_EQUAL(value, popped_val);
    TEST_ASSERT_EQUAL(0, s->length);

    popped_val = -1;
    n_pops = pop(s, &popped_val);
    TEST_ASSERT_EQUAL(0, n_pops);
    TEST_ASSERT_EQUAL(-1, popped_val);
    TEST_ASSERT_NULL(s->head);

    TEST_ASSERT_EQUAL(0, delete_stack(s));
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_push_stack);
    RUN_TEST(test_pop_stack);

    return UNITY_END();
}
