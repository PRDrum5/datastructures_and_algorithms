add_subdirectory(lib)
list(APPEND EXTRA_LIBS_Trees TreesLib)

add_executable(Trees main.c)

target_link_libraries(Trees
                      PUBLIC
                      ${EXTRA_LIBS_Trees}
                      )

target_include_directories(Trees
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_Trees}
                           )
