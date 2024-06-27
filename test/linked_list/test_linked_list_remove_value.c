#include <unity.h>

#include "linked_list.h"

void test_remove_value_linked_list(void) {
    const int v = 42;
    linked_list_t *list = new_linked_list(v);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(42, list->head->value);

    const int new_value = 1;
    int status = prepend(list, new_value);
    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL(new_value, list->head->value);
    TEST_ASSERT_EQUAL(v, list->head->next->value);
    TEST_ASSERT_EQUAL(0, status);

    const int another_value = 5;
    status = prepend(list, another_value);
    TEST_ASSERT_EQUAL(3, list->length);
    TEST_ASSERT_EQUAL(another_value, list->head->value);
    TEST_ASSERT_EQUAL(new_value, list->head->next->value);
    TEST_ASSERT_EQUAL(v, list->head->next->next->value);
    TEST_ASSERT_EQUAL(0, status);

    int removal_count = -1;
    removal_count = remove_value(list, new_value);
    TEST_ASSERT_EQUAL(1, removal_count);
    TEST_ASSERT_EQUAL(2, list->length);
    // Check that it's gone
    int missing_value = -1;
    for (int i = 0; i < list->length; i++) {
        TEST_ASSERT_EQUAL(1, get(list, 1, &missing_value));
        TEST_ASSERT_NOT_EQUAL(new_value, missing_value);
    }

    removal_count = -1;
    removal_count = remove_value(list, 100);
    TEST_ASSERT_EQUAL(0, removal_count);
    TEST_ASSERT_EQUAL(2, list->length);

    removal_count = -1;
    removal_count = remove_value(list, another_value);
    TEST_ASSERT_EQUAL(1, removal_count);
    TEST_ASSERT_EQUAL(1, list->length);
    // Check that it's gone
    missing_value = -1;
    for (int i = 0; i < list->length; i++) {
        TEST_ASSERT_EQUAL(1, get(list, 0, &missing_value));
        TEST_ASSERT_NOT_EQUAL(another_value, missing_value);
    }

    removal_count = -1;
    removal_count = remove_value(list, v);
    TEST_ASSERT_EQUAL(1, removal_count);
    TEST_ASSERT_EQUAL(0, list->length);

    removal_count = -1;
    removal_count = remove_value(list, v);
    TEST_ASSERT_EQUAL(0, removal_count);

    free_linked_list(list);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_remove_value_linked_list);

    return UNITY_END();
}
