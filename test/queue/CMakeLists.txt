add_executable(test_queue_create 
    test_queue_create.c
)
add_executable(test_queue_enqueue 
    test_queue_enqueue.c
)
add_executable(test_queue_dequeue 
    test_queue_dequeue.c
)
add_executable(test_queue_peek 
    test_queue_peek.c
)

target_link_libraries(test_queue_create
    QueueLib 
    Unity
)
target_link_libraries(test_queue_enqueue
    QueueLib 
    Unity
)
target_link_libraries(test_queue_dequeue
    QueueLib 
    Unity
)
target_link_libraries(test_queue_peek
    QueueLib 
    Unity
)

add_test(test_queue_create test_queue_create)
add_test(test_queue_enqueue test_queue_enqueue)
add_test(test_queue_dequeue test_queue_dequeue)
add_test(test_queue_peek test_queue_peek)
