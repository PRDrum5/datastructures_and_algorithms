#include <unity.h>

#include "queue.h"

void test_enqueue(void) {
    queue_t *queue = new_queue();
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_EQUAL(0, queue->length);

    const int first_in = 0;
    int status = enqueue(queue, first_in);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(1, queue->length);
    TEST_ASSERT_EQUAL(first_in, queue->head->value);
    TEST_ASSERT_EQUAL(first_in, queue->tail->value);

    const int second_in = 1;
    status = enqueue(queue, second_in);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(2, queue->length);
    TEST_ASSERT_EQUAL(first_in, queue->head->value);
    TEST_ASSERT_EQUAL(second_in, queue->tail->value);

    const int third_in = 2;
    status = enqueue(queue, third_in);
    TEST_ASSERT_EQUAL(0, status);
    TEST_ASSERT_EQUAL(3, queue->length);
    TEST_ASSERT_EQUAL(first_in, queue->head->value);
    TEST_ASSERT_EQUAL(third_in, queue->tail->value);

    delete_queue(queue);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_enqueue);

    return UNITY_END();
}
