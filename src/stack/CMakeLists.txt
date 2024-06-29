add_subdirectory(lib)
list(APPEND EXTRA_LIBS_Stack StackLib)

add_executable(Stack main.c)

target_link_libraries(Stack
                      PUBLIC
                      ${EXTRA_LIBS_Stack}
                      )

target_include_directories(Stack
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Stack}
                           )
