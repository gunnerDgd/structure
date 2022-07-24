cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure-dll
    VERSION 0.1.0
    LANGUAGES C
)

file(
    GLOB_RECURSE
    src_synapse_structure_dll
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
    synapse_structure_dll
    SHARED
    ${src_synapse_structure_dll}
)

target_link_libraries(
    synapse_structure_dll
    synapse_structure_cqueue_lib
    synapse_structure_spsc_lib
    synapse_structure_mpmc_lib
    synapse_structure_slist_lib
    synapse_structure_dlist_lib
    synapse_memory_dll
)

target_include_directories(
    synapse_structure_dll 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
    synapse_structure_dll
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

target_compile_options(
    synapse_structure_dll
    PUBLIC
    /Dsynapse_structure_export_mode
)