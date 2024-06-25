add_library(LinkedListLib linked_list.c)

target_include_directories(LinkedListLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
