#include "stack.h"
#include <unity.h>

void test_new_stack(void) {
    const int value = 100;
    stack_t *s = new_stack(value);

    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_NOT_NULL(s->head);
    TEST_ASSERT_EQUAL(1, s->length);
    TEST_ASSERT_EQUAL(value, s->head->value);
    TEST_ASSERT_NULL(s->head->prev);

    TEST_ASSERT_EQUAL(0, delete_stack(s));
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_new_stack);

    return UNITY_END();
}
