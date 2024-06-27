add_library(LinkedListLib STATIC linked_list.c)

target_include_directories(LinkedListLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
