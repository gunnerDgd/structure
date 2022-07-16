cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure
    VERSION 0.1.0
    LANGUAGES C
)

set(
    synapse_slist_standalone_build 
    OFF
)

set(
    synapse_dlist_standalone_build
    OFF
)

add_subdirectory(source/c/list/double_linked)
