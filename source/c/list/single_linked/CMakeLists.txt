cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure-single-linked-lib
    VERSION 0.1.0
    LANGUAGES C


if(NOT synapse_slist_standalone_build)
file(
    GLOB_RECURSE
    src_synapse_structure_slist_lib
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)
else()
file(
    GLOB_RECURSE
    src_synapse_structure_slist_lib
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/*.c
)
endif()

add_library(
    synapse_structure_slist_lib
    STATIC
    ${src_synapse_structure_slist_lib}
) 

if(NOT synapse_slist_standalone_build)
    target_include_directories(
        synapse_structure_slist_lib 
        PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    )
else()
    target_include_directories(
        synapse_structure_slist_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../include
        )
endif()

target_include_directories(
    synapse_structure_slist_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../../include
)
