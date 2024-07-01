add_subdirectory(lib)
list(APPEND EXTRA_LIBS_ArrayList ArrayListLib)

target_link_libraries(ArrayList
                      PUBLIC
                      ${EXTRA_LIBS_ArrayList}
                      )

target_include_directories(ArrayList
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS_ArrayList}
                           )
