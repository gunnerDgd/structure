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
    synapse_structure_lib
    synapse_memory_dll
)

target_include_directories(
    synapse_structure_dll 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include
)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    set_target_properties(
        synapse_structure_dll
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/lib/build
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )

    target_compile_options(
        synapse_structure_dll 
        PRIVATE 
        /Dsynapse_structure_export_mode
    )

    target_link_libraries(
        synapse_structure_dll
        ws2_32.lib
    )
elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    set_target_properties(
        synapse_structure_dll
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )

    target_compile_options(
        synapse_structure_dll 
        PRIVATE 
        -Dsynapse_structure_export_mode
    )
endif()

target_link_libraries(
    synapse_structure_dll
    synapse_memory_dll
)