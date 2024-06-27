#include <unity.h>

#include "linked_list.h"

void test_remove_at_linked_list(void) {
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

    int remove_value = -1;
    int index = 0;
    status = remove_at(list, index, &remove_value);
    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL(another_value, remove_value);
    TEST_ASSERT_EQUAL(0, status);

    remove_value = -1;
    index = 1;
    status = remove_at(list, index, &remove_value);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(v, remove_value);
    TEST_ASSERT_EQUAL(0, status);

    remove_value = -1;
    index = 1;
    status = remove_at(list, index, &remove_value);
    TEST_ASSERT_EQUAL(1, status);

    remove_value = -1;
    index = 0;
    status = remove_at(list, index, &remove_value);
    TEST_ASSERT_EQUAL(0, list->length);
    TEST_ASSERT_EQUAL(new_value, remove_value);
    TEST_ASSERT_EQUAL(0, status);

    free_linked_list(list);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_remove_at_linked_list);

    return UNITY_END();
}
