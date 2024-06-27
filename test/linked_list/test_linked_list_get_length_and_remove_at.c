#include <unity.h>

#include "linked_list.h"

void test_length_of_linked_list(void) {
    const int v = 42;
    linked_list_t *list = new_linked_list(v);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(42, list->head->value);

    const int new_value = 1;
    int status = prepend(list, new_value);
    TEST_ASSERT_EQUAL(2, get_length(list));
    TEST_ASSERT_EQUAL(new_value, list->head->value);
    TEST_ASSERT_EQUAL(v, list->head->next->value);
    TEST_ASSERT_EQUAL(0, status);

    const int another_value = 5;
    status = prepend(list, another_value);
    TEST_ASSERT_EQUAL(3, get_length(list));
    TEST_ASSERT_EQUAL(another_value, list->head->value);
    TEST_ASSERT_EQUAL(new_value, list->head->next->value);
    TEST_ASSERT_EQUAL(v, list->head->next->next->value);
    TEST_ASSERT_EQUAL(0, status);

    free_linked_list(list);
}
void test_length_of_linked_list_and_remove_at(void) {
    const int v = 42;
    linked_list_t *list = new_linked_list(v);
    TEST_ASSERT_NOT_NULL(list);
    TEST_ASSERT_NOT_NULL(list->head);
    TEST_ASSERT_EQUAL(1, list->length);
    TEST_ASSERT_EQUAL(42, list->head->value);

    const int new_value = 1;
    int status = prepend(list, new_value);
    TEST_ASSERT_EQUAL(2, get_length(list));
    TEST_ASSERT_EQUAL(new_value, list->head->value);
    TEST_ASSERT_EQUAL(v, list->head->next->value);
    TEST_ASSERT_EQUAL(0, status);

    const int another_value = 5;
    status = prepend(list, another_value);
    TEST_ASSERT_EQUAL(3, get_length(list));
    TEST_ASSERT_EQUAL(another_value, list->head->value);
    TEST_ASSERT_EQUAL(new_value, list->head->next->value);
    TEST_ASSERT_EQUAL(v, list->head->next->next->value);
    TEST_ASSERT_EQUAL(0, status);

    int remove_val = -1;
    status = remove_at(list, 0, &remove_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(another_value, remove_val);
    TEST_ASSERT_EQUAL(2, get_length(list));

    status = remove_at(list, 0, &remove_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(new_value, remove_val);
    TEST_ASSERT_EQUAL(1, get_length(list));

    status = remove_at(list, 0, &remove_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(v, remove_val);
    TEST_ASSERT_EQUAL(0, get_length(list));

    status = remove_at(list, 0, &remove_val);
    TEST_ASSERT_EQUAL(1, status);

    free_linked_list(list);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_length_of_linked_list);
    RUN_TEST(test_length_of_linked_list_and_remove_at);

    return UNITY_END();
}
