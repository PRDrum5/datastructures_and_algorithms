add_subdirectory(lib)
list(APPEND EXTRA_LIBS_Sort SortLib)

add_executable(BubbleSort bubble_sort.c)
target_link_libraries(BubbleSort
                      PUBLIC
                      ${EXTRA_LIBS_Sort}
                      )
target_include_directories(BubbleSort
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Sort}
                           )

add_executable(QuickSort quick_sort.c)
target_link_libraries(QuickSort
                      PUBLIC
                      ${EXTRA_LIBS_Sort}
                      )
target_include_directories(QuickSort
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Sort}
                           )
