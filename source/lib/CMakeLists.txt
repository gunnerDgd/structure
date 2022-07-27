cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure-lib
    VERSION 0.1.0
    LANGUAGES C
)

file(
    GLOB_RECURSE
    src_synapse_structure_lib
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_library(
    synapse_structure_lib
    STATIC
    ${src_synapse_structure_lib}
)

target_include_directories(
    synapse_structure_lib 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    target_compile_options(
        synapse_structure_lib
        PUBLIC
        /DSYNAPSE_BUILD_ENVIRONMENT_MSVC
    )
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(
        synapse_structure_lib
        PUBLIC
        -DSYNAPSE_BUILD_ENVIRONMENT_GCC
    )
endif()