#include <unity.h>

#include "array_list.h"

void test_array_list_new(void) {
    size_t capacity = 4;
    array_list_t *arr = new_array_list(capacity);

    TEST_ASSERT_NOT_NULL(arr);
    TEST_ASSERT_NOT_NULL(arr->head);
    TEST_ASSERT_EQUAL(0, arr->length);
    TEST_ASSERT_EQUAL(capacity, arr->capacity);

    delete_array_list(arr);
}

void test_array_list_fail_huge_array(void) {
    size_t capacity = 0xffffffff;
    array_list_t *arr = new_array_list(capacity);

    TEST_ASSERT_NULL(arr);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_array_list_new);
    RUN_TEST(test_array_list_fail_huge_array);

    return UNITY_END();
}
