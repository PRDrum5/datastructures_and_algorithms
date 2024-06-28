#include <unity.h>

#include "queue.h"

void test_peek(void) {
    const int first_in = 0;
    queue_t *queue = new_queue(first_in);
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->head);
    TEST_ASSERT_NOT_NULL(queue->head);
    TEST_ASSERT_EQUAL(1, queue->length);

    int value = 99;
    int status = peek(queue, &value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(first_in, value);

    value = 99;
    const int second_in = 1;
    status = enqueue(queue, second_in);
    TEST_ASSERT_EQUAL(0, status);
    status = peek(queue, &value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(first_in, value);

    value = 99;
    const int third_in = 2;
    status = enqueue(queue, third_in);
    TEST_ASSERT_EQUAL(0, status);
    status = peek(queue, &value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(first_in, value);

    int dq_value = -1;
    status = dequeue(queue, &dq_value);
    TEST_ASSERT_EQUAL(0, status);

    status = peek(queue, &value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(second_in, value);

    dq_value = -1;
    status = dequeue(queue, &dq_value);
    TEST_ASSERT_EQUAL(0, status);

    status = peek(queue, &value);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(third_in, value);

    dq_value = -1;
    status = dequeue(queue, &dq_value);
    TEST_ASSERT_EQUAL(0, status);

    status = peek(queue, &value);
    TEST_ASSERT_EQUAL(1, status);
    TEST_ASSERT_EQUAL(third_in, value);

    delete_queue(queue);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_peek);

    return UNITY_END();
}
