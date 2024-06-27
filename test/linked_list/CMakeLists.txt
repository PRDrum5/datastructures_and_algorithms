add_executable(test_linked_list_create 
    test_linked_list_create.c
)
add_executable(test_linked_list_append 
    test_linked_list_append.c
)
add_executable(test_linked_list_prepend 
    test_linked_list_prepend.c
)
add_executable(test_linked_list_get_length_and_remove_at
    test_linked_list_get_length_and_remove_at.c
)
add_executable(test_linked_list_insert_and_get
    test_linked_list_insert_and_get.c
)
add_executable(test_linked_list_remove_at 
    test_linked_list_remove_at.c
)
add_executable(test_linked_list_remove_value 
    test_linked_list_remove_value.c
)

target_link_libraries(test_linked_list_create
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_append
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_prepend
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_get_length_and_remove_at
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_insert_and_get
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_remove_at
    LinkedListLib 
    Unity
)
target_link_libraries(test_linked_list_remove_value
    LinkedListLib 
    Unity
)

add_test(linked_list_create_test test_linked_list_create)
add_test(linked_list_append_test test_linked_list_append)
add_test(linked_list_prepend_test test_linked_list_prepend)
add_test(test_linked_list_get_length_and_remove_at test_linked_list_get_length_and_remove_at)
add_test(test_linked_list_insert_and_get test_linked_list_insert_and_get)
add_test(test_linked_list_remove_at test_linked_list_remove_at)
add_test(test_linked_list_remove_value test_linked_list_remove_value)
