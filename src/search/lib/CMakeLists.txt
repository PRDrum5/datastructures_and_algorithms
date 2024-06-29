add_library(SearchLib STATIC search_algorithms.c)

target_include_directories(SearchLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

