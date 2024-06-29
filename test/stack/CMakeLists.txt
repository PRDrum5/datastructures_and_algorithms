add_executable(test_stack_create 
    test_stack_create.c
)
add_executable(test_stack_peek 
    test_stack_peek.c
)
add_executable(test_stack_push_pop 
    test_stack_push_pop.c
)

target_link_libraries(test_stack_create
    StackLib 
    Unity
)
target_link_libraries(test_stack_peek
    StackLib 
    Unity
)
target_link_libraries(test_stack_push_pop
    StackLib 
    Unity
)

add_test(test_stack_create test_stack_create)
add_test(test_stack_peek test_stack_peek)
add_test(test_stack_push_pop test_stack_push_pop)
