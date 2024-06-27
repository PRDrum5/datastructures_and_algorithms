#include <unity.h>

#include "linked_list.h"

void test_new_linked_list(void) {
    const int v = 42;
    linked_list_t *list = new_linked_list(v);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(42, list->head->value);
    free_linked_list(list);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_new_linked_list);

    return UNITY_END();
}
