#include <unity.h>

#include "queue.h"

void test_new_queue(void) {
    const int first_in = 0;
    queue_t *queue = new_queue(first_in);
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NOT_NULL(queue->head);
    TEST_ASSERT_NOT_NULL(queue->head);

    TEST_ASSERT_EQUAL(1, queue->length);
    TEST_ASSERT_EQUAL(0, queue->head->value);
    TEST_ASSERT_EQUAL(0, queue->tail->value);
    delete_queue(queue);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_new_queue);

    return UNITY_END();
}
