add_subdirectory(lib)
list(APPEND EXTRA_LIBS_Search SearchLib)

add_executable(Linear_Search linear_search.c)
target_link_libraries(Linear_Search
                      PUBLIC
                      ${EXTRA_LIBS_Search}
                      )
target_include_directories(Linear_Search
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Search}
                           )

add_executable(Binary_Search binary_search.c)
target_link_libraries(Binary_Search
                      PUBLIC
                      ${EXTRA_LIBS_Search}
                      )
target_include_directories(Binary_Search
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Search}
                           )

