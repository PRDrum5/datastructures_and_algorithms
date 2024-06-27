#include <unity.h>

#include "linked_list.h"
#include "unity_internals.h"

void test_get_linked_list(void) {
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

    int gotten_value = -1;
    int n_returns = -1;
    n_returns = get(list, 0, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(another_value, gotten_value);

    n_returns = -1;
    n_returns = get(list, 2, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(v, gotten_value);

    gotten_value = -1;
    n_returns = -1;
    n_returns = get(list, 3, &gotten_value);
    TEST_ASSERT_EQUAL(0, n_returns);
    TEST_ASSERT_EQUAL(-1, gotten_value);

    free_linked_list(list);
}

void test_insert_at_linked_list(void) {
    const int v = 42;
    linked_list_t *list = new_linked_list(v);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(42, list->head->value);

    const int value_at_0 = 1;
    int index = 0;
    int status = insert_at(list, value_at_0, index);
    TEST_ASSERT_EQUAL(2, list->length);
    TEST_ASSERT_EQUAL(0, status);

    int gotten_value = -1;
    int n_returns = -1;
    n_returns = get(list, 0, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(value_at_0, gotten_value);

    n_returns = get(list, 1, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(v, gotten_value);

    TEST_ASSERT_EQUAL(2, list->length);

    const int value_at_2 = 5;
    index = 1;
    status = insert_at(list, value_at_2, index);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(3, list->length);

    gotten_value = -1;
    n_returns = -1;
    n_returns = get(list, 1, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(value_at_2, gotten_value);

    n_returns = get(list, 0, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(value_at_0, gotten_value);

    n_returns = get(list, 2, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(v, gotten_value);

    const int value_at_1 = 10;
    index = 1;
    status = insert_at(list, value_at_1, index);
    TEST_ASSERT_EQUAL(4, list->length);
    TEST_ASSERT_EQUAL(0, status);

    gotten_value = -1;
    n_returns = -1;
    n_returns = get(list, 1, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(value_at_1, gotten_value);

    n_returns = get(list, 0, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(value_at_0, gotten_value);

    n_returns = get(list, 3, &gotten_value);
    TEST_ASSERT_EQUAL(1, n_returns);
    TEST_ASSERT_EQUAL(v, gotten_value);

    const int value_out_of_bounds = 99;
    index = 4;
    status = insert_at(list, value_out_of_bounds, index);
    TEST_ASSERT_EQUAL(1, status);

    free_linked_list(list);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_get_linked_list);
    RUN_TEST(test_insert_at_linked_list);

    return UNITY_END();
}
