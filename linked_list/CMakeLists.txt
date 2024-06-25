cmake_minimum_required(VERSION 3.24.0)

project(LinkedLists VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)
list(APPEND EXTRA_LIBS LinkedListLib)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME}
                      PUBLIC
                      ${EXTRA_LIBS}
                      )

target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           "${PUBLIC_BINARY_DIR}"
                           ${EXTRA_LIBS}
                           )
