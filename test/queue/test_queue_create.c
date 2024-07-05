#include <unity.h>

#include "queue.h"

void test_new_queue(void) {
    queue_t *queue = new_queue();
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_NULL(queue->head);
    TEST_ASSERT_NULL(queue->head);

    TEST_ASSERT_EQUAL(0, queue->length);
    delete_queue(queue);
}

void setUp(void) {}
void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_new_queue);

    return UNITY_END();
}
