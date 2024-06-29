#include "stack.h"
#include <unity.h>

void test_peek_stack(void) {
    const int value = 100;
    stack_t *s = new_stack(value);

    TEST_ASSERT_NOT_NULL(s);

    int peeked_value = -1;
    TEST_ASSERT_EQUAL(0, peek(s, &peeked_value));
    TEST_ASSERT_EQUAL(value, peeked_value);

    int modify_value = value + 20;
    s->head->value = modify_value;
    TEST_ASSERT_EQUAL(1, s->length);
    TEST_ASSERT_NULL(s->head->prev);

    TEST_ASSERT_EQUAL(0, peek(s, &peeked_value));
    TEST_ASSERT_EQUAL(modify_value, peeked_value);

    TEST_ASSERT_EQUAL(0, delete_stack(s));
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_peek_stack);

    return UNITY_END();
}
