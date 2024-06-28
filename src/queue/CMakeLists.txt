add_subdirectory(lib)
list(APPEND EXTRA_LIBS_Queue QueueLib)

add_executable(Queue main.c)

target_link_libraries(Queue
                      PUBLIC
                      ${EXTRA_LIBS_Queue}
                      )

target_include_directories(Queue
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Queue}
                           )
