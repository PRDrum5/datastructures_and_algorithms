#include <unity.h>

#include "ring_buffer.h"

void test_ring_buffer_enqueue(void) {
    const size_t capacity = 2;
    ring_buffer_t *buffer = new_ring_buffer(capacity);
    TEST_ASSERT_NOT_NULL(buffer);

    int status = -1;
    const int value = 5;
    status = enqueue(buffer, value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(1, buffer->write);

    status = -1;
    const int value_2 = 6;
    status = enqueue(buffer, value_2);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(2, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(0, buffer->write);

    delete_ring_buffer(buffer);
}

void test_ring_buffer_enqueue_expand(void) {
    const size_t capacity = 2;
    ring_buffer_t *buffer = new_ring_buffer(capacity);
    TEST_ASSERT_NOT_NULL(buffer);

    int status = -1;
    const int value = 5;
    status = enqueue(buffer, value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(1, buffer->write);

    status = -1;
    const int value_2 = 6;
    status = enqueue(buffer, value_2);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(2, buffer->length);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(0, buffer->write);

    status = -1;
    const int value_3 = 7;
    status = enqueue(buffer, value_3);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(3, buffer->length);
    TEST_ASSERT_EQUAL(2 * capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(3, buffer->write);

    status = -1;
    const int value_4 = 8;
    status = enqueue(buffer, value_4);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(4, buffer->length);
    TEST_ASSERT_EQUAL(2 * capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(0, buffer->write);

    status = -1;
    const int value_5 = 9;
    status = enqueue(buffer, value_5);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(5, buffer->length);
    TEST_ASSERT_EQUAL(2 * 2 * capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(5, buffer->write);

    delete_ring_buffer(buffer);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ring_buffer_enqueue);
    RUN_TEST(test_ring_buffer_enqueue_expand);

    return UNITY_END();
}
