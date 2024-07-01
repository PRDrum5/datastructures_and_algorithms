#include <unity.h>

#include "array_list.h"

void test_array_list_push(void) {
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

    val = 1;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[1]);
    TEST_ASSERT_EQUAL(2, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    val = 2;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[2]);
    TEST_ASSERT_EQUAL(3, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    val = 3;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[3]);
    TEST_ASSERT_EQUAL(4, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    delete_array_list(arr);
}

void test_array_list_push_and_extend(void) {
    size_t capacity = 2;
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

    val = 1;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[1]);
    TEST_ASSERT_EQUAL(2, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    size_t new_capacity = capacity * 2;
    val = 2;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[2]);
    TEST_ASSERT_EQUAL(3, arr->length);
    TEST_ASSERT_EQUAL(new_capacity, arr->capacity);

    val = 3;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[3]);
    TEST_ASSERT_EQUAL(4, arr->length);
    TEST_ASSERT_EQUAL(new_capacity, arr->capacity);

    size_t even_newer_capacity = new_capacity * 2;
    val = 4;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[4]);
    TEST_ASSERT_EQUAL(5, arr->length);
    TEST_ASSERT_EQUAL(even_newer_capacity, arr->capacity);

    val = 5;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[5]);
    TEST_ASSERT_EQUAL(6, arr->length);
    TEST_ASSERT_EQUAL(even_newer_capacity, arr->capacity);

    val = 6;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[6]);
    TEST_ASSERT_EQUAL(7, arr->length);
    TEST_ASSERT_EQUAL(even_newer_capacity, arr->capacity);

    val = 7;
    status = push(arr, val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(val, arr->head[7]);
    TEST_ASSERT_EQUAL(8, arr->length);
    TEST_ASSERT_EQUAL(even_newer_capacity, arr->capacity);

    delete_array_list(arr);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_array_list_push);
    RUN_TEST(test_array_list_push_and_extend);

    return UNITY_END();
}
