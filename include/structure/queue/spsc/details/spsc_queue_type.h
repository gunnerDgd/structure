#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct
    __synapse_structure_spsc_queue_node
{
    void*
        ptr_node_data;
    volatile
        struct __synapse_structure_spsc_queue_node*
            ptr_node_next;
} __synapse_structure_spsc_queue_node;

typedef struct
    __synapse_structure_spsc_queue_probe
{
    volatile
        __synapse_structure_spsc_queue_node*
            ptr_probe_access;
    uint32_t
        pid_probe;
} __synapse_structure_spsc_queue_probe;

typedef struct
    __synapse_structure_spsc_queue
{
    void*
        ptr_spsc_arena;
    __synapse_structure_spsc_queue_node*
        ptr_spsc_node ;

    __synapse_structure_spsc_queue_probe
        prb_spsc_read ,
        prb_spsc_write;    
} __synapse_structure_spsc_queue;