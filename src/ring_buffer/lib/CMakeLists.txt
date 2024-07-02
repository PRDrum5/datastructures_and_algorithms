add_library(RingBufferLib STATIC ring_buffer.c)

target_include_directories(RingBufferLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
