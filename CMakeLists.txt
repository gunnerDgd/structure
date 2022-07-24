cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure
    VERSION 0.1.0
    LANGUAGES C
)

add_subdirectory(source/c/queue/spsc)
add_subdirectory(source/c/queue/mpmc)
add_subdirectory(source/c/queue/circular)

add_subdirectory(source/c/list/single_linked)
add_subdirectory(source/c/list/double_linked)

add_subdirectory(source/shared_libs)