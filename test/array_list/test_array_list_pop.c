#include <unity.h>

#include "array_list.h"

void test_array_list_pop(void) {
    size_t capacity = 4;
    array_list_t *arr = new_array_list(capacity);

    TEST_ASSERT_NOT_NULL(arr);
    TEST_ASSERT_NOT_NULL(arr->head);
    TEST_ASSERT_EQUAL(0, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    int val = 0;
    int status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[0]);
    TEST_ASSERT_EQUAL(1, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    int popped_val = -1;
    status = 1;
    status = pop(arr, &popped_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, popped_val);
    TEST_ASSERT_EQUAL(0, arr->length);

    popped_val = -1;
    status = 1;
    status = pop(arr, &popped_val);
    TEST_ASSERT_EQUAL(1, status);
    TEST_ASSERT_EQUAL(-1, popped_val);
    TEST_ASSERT_EQUAL(0, arr->length);

    delete_array_list(arr);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_array_list_pop);

    return UNITY_END();
}
