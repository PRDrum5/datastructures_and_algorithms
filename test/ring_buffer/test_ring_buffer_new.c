#include <unity.h>

#include "ring_buffer.h"

void test_ring_buffer_new(void) {
    const size_t capacity = 4;
    ring_buffer_t *buffer = new_ring_buffer(capacity);

    TEST_ASSERT_NOT_NULL(buffer);
    TEST_ASSERT_NOT_NULL(buffer->data);
    TEST_ASSERT_EQUAL(capacity, buffer->capacity);
    TEST_ASSERT_EQUAL(0, buffer->length);
    TEST_ASSERT_EQUAL(0, buffer->read);
    TEST_ASSERT_EQUAL(0, buffer->write);

    delete_ring_buffer(buffer);
}

void test_ring_buffer_failed_new(void) {
    const size_t capacity = 0xFFFFFFFF;
    ring_buffer_t *buffer = new_ring_buffer(capacity);

    TEST_ASSERT_NULL(buffer);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_ring_buffer_new);
    RUN_TEST(test_ring_buffer_failed_new);

    return UNITY_END();
}
