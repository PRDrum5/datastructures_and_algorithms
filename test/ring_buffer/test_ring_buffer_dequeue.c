#include <unity.h>

#include "ring_buffer.h"

void test_ring_buffer_dequeue(void) {
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

    int dq_value = -1;
    status = -1;
    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, dq_value);
    TEST_ASSERT_EQUAL(0, buffer->length);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(1, status);

    status = enqueue(buffer, value_0);
    TEST_ASSERT_EQUAL(0, status);

    const int value_1 = 1;
    status = enqueue(buffer, value_1);
    TEST_ASSERT_EQUAL(0, status);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, dq_value);
    TEST_ASSERT_EQUAL(1, buffer->length);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, dq_value);
    TEST_ASSERT_EQUAL(0, buffer->length);
}

void test_ring_buffer_dequeue_with_resize(void) {
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
    TEST_ASSERT_EQUAL(0, buffer->read);

    int dq_value = -1;
    status = -1;
    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(0, dq_value);
    TEST_ASSERT_EQUAL(2, buffer->length);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, dq_value);
    TEST_ASSERT_EQUAL(1, buffer->length);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(2, dq_value);
    TEST_ASSERT_EQUAL(0, buffer->length);

    status = dequeue(buffer, &dq_value);
    TEST_ASSERT_EQUAL(1, status);
}
void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ring_buffer_dequeue);
    RUN_TEST(test_ring_buffer_dequeue_with_resize);

    return UNITY_END();
}
