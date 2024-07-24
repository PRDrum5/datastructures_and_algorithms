add_library(TreesLib STATIC trees.c bfsearch.c)

target_include_directories(TreesLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
