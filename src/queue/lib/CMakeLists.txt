add_library(QueueLib STATIC queue.c)

target_include_directories(QueueLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
