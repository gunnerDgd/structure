cmake_minimum_required(VERSION 3.0)

project(
    synapse-structure-single-linked-lib
    VERSION 0.1.0
    LANGUAGES C
)

if(SYNAPSE_BUILD_LINUX)
    file(
        GLOB_RECURSE
        src_synapse_structure_slist_lib
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/details/linux/*.c
    ) 
elseif(SYNAPSE_BUILD_WINDOWS)
    file(
        GLOB
        src_synapse_structure_slist_lib
        CONFIGURE_DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/details/*.c
    )
endif()


add_library(
    synapse_structure_slist_lib
    STATIC
    ${src_synapse_structure_slist_lib}
    slist.c
) 

target_include_directories(
    synapse_structure_slist_lib 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_include_directories(
    synapse_structure_slist_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../../include
)

