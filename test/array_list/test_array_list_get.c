#include <unity.h>

#include "array_list.h"

void test_array_list_get(void) {
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

    int get_val = -1;
    size_t idx = 0;
    status = 1;
    status = get(arr, idx, &get_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, get_val);
    TEST_ASSERT_EQUAL(4, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    get_val = -1;
    idx = 3;
    status = 1;
    status = get(arr, idx, &get_val);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(3, get_val);
    TEST_ASSERT_EQUAL(4, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    get_val = -1;
    idx = 4;
    status = 1;
    status = get(arr, idx, &get_val);
    TEST_ASSERT_EQUAL(1, status);
    TEST_ASSERT_EQUAL(-1, get_val);
    TEST_ASSERT_EQUAL(4, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    delete_array_list(arr);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_array_list_get);

    return UNITY_END();
}
