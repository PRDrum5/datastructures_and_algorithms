add_library(StackLib STATIC stack.c)

target_include_directories(StackLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
