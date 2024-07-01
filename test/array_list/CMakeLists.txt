add_executable(test_array_list_new 
    test_array_list_new.c
)
add_executable(test_array_list_push
    test_array_list_push.c
)
add_executable(test_array_list_pop
    test_array_list_pop.c
)
add_executable(test_array_list_get
    test_array_list_get.c
)

target_link_libraries(test_array_list_new
    ArrayListLib 
    Unity
)
target_link_libraries(test_array_list_push
    ArrayListLib 
    Unity
)
target_link_libraries(test_array_list_pop
    ArrayListLib 
    Unity
)
target_link_libraries(test_array_list_get
    ArrayListLib 
    Unity
)

add_test(test_array_list_new test_array_list_new)
add_test(test_array_list_push test_array_list_push)
add_test(test_array_list_pop test_array_list_pop)
add_test(test_array_list_get test_array_list_get)
