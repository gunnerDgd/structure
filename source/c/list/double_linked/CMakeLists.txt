cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure-double-linked-lib
    VERSION 0.1.0
    LANGUAGES C
)

file(
    GLOB src_synapse_structure_dlist_lib CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
  synapse_structure_dlist_lib STATIC ${src_synapse_structure_dlist_lib}
)

target_include_directories(
    synapse_structure_dlist_lib PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
    synapse_structure_dlist_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../../include
)