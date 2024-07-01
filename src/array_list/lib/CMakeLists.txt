add_library(ArrayListLib STATIC array_list.c)

target_include_directories(ArrayListLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
