add_library(SortLib STATIC bubble.c quick.c)
target_include_directories(SortLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
