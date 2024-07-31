add_library(PriorityQueueLib STATIC priority_queue.c)

target_link_directories(PriorityQueueLib PUBLIC "../../array_list/")
target_link_libraries(PriorityQueueLib PUBLIC ArrayListLib)

target_include_directories(PriorityQueueLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
