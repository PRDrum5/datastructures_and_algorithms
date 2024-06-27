add_subdirectory(lib)
list(APPEND EXTRA_LIBS_LinkedList LinkedListLib)

add_executable(LinkedList main.c)

target_link_libraries(LinkedList
                      PUBLIC
                      ${EXTRA_LIBS_LinkedList}
                      )

target_include_directories(LinkedList
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_LinkedList}
                           )
