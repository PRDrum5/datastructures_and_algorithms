add_executable(test_ring_buffer_dequeue
    test_ring_buffer_dequeue.c
)
add_executable(test_ring_buffer_enqueue 
    test_ring_buffer_enqueue.c
)
add_executable(test_ring_buffer_get
    test_ring_buffer_get.c
)
add_executable(test_ring_buffer_new 
    test_ring_buffer_new.c
)

target_link_libraries(test_ring_buffer_dequeue
    RingBufferLib 
    Unity
)
target_link_libraries(test_ring_buffer_enqueue
    RingBufferLib 
    Unity
)
target_link_libraries(test_ring_buffer_get
    RingBufferLib 
    Unity
)
target_link_libraries(test_ring_buffer_new
    RingBufferLib 
    Unity
)

add_test(test_ring_buffer_dequeue test_ring_buffer_dequeue)
add_test(test_ring_buffer_enqueue test_ring_buffer_enqueue)
add_test(test_ring_buffer_get test_ring_buffer_get)
add_test(test_ring_buffer_new test_ring_buffer_new)
