add_subdirectory(lib)

add_executable(PriorityQueue main.c)

target_link_libraries(PriorityQueue
                      PUBLIC
                      PriorityQueueLib
                      )

target_include_directories(PriorityQueue
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           PriorityQueueLib
                           )
