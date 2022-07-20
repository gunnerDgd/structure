cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure
    VERSION 0.1.0
    LANGUAGES C
)

option(SYNAPSE_STRUCTIRE_SLIST_STANDALONE OFF)
option(SYNAPSE_STRUCTIRE_DLIST_STANDALONE OFF)

add_subdirectory(source/c/list/double_linked)
