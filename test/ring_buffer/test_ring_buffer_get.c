#include <unity.h>

#include "ring_buffer.h"

void test_ring_buffer_get(void) {
    const size_t capacity = 4;
    ring_buffer_t *buffer = new_ring_buffer(capacity);
    TEST_ASSERT_NOT_NULL(buffer);

    int status = -1;
    const int value_0 = 0;
    status = enqueue(buffer, value_0);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(1, buffer->write);

    int get_value = -1;
    int idx = 0;
    status = -1;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, get_value);
    TEST_ASSERT_EQUAL(1, buffer->length);

    idx = 1;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(1, status);
}

void test_ring_buffer_get_with_resize(void) {
    const size_t capacity = 2;
    ring_buffer_t *buffer = new_ring_buffer(capacity);
    TEST_ASSERT_NOT_NULL(buffer);

    int status = -1;
    const int value_0 = 0;
    status = enqueue(buffer, value_0);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(1, buffer->write);

    const int value_1 = 1;
    status = enqueue(buffer, value_1);
    TEST_ASSERT_EQUAL(0, status);

    const int value_2 = 2;
    status = enqueue(buffer, value_2);
    TEST_ASSERT_EQUAL(0, status);

    TEST_ASSERT_EQUAL(3, buffer->length);

    int get_value = -1;
    int idx = 0;
    status = -1;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, get_value);
    TEST_ASSERT_EQUAL(3, buffer->length);

    idx = 1;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, get_value);
    TEST_ASSERT_EQUAL(3, buffer->length);

    idx = 2;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(2, get_value);
    TEST_ASSERT_EQUAL(3, buffer->length);

    idx = 3;
    status = get(buffer, idx, &get_value);
    TEST_ASSERT_EQUAL(1, status);
}
void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ring_buffer_get);
    RUN_TEST(test_ring_buffer_get_with_resize);

    return UNITY_END();
}
