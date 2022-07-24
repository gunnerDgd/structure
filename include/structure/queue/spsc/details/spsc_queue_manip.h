#pragma once

#include <structure/queue/spsc/details/spsc_queue_type.h>
#include <stdbool.h>

__synapse_structure_spsc_queue_probe*
    __synapse_structure_spsc_queue_read_probe
        (__synapse_structure_spsc_queue*);

__synapse_structure_spsc_queue_probe*
    __synapse_structure_spsc_queue_write_probe
        (__synapse_structure_spsc_queue*);

void*
    __synapse_structure_spsc_queue_read_from
        (__synapse_structure_spsc_queue*, 
         __synapse_structure_spsc_queue_probe*);

void*
    __synapse_structure_spsc_queue_read_from_until_success
        (__synapse_structure_spsc_queue*, 
         __synapse_structure_spsc_queue_probe*);

bool
    __synapse_structure_spsc_queue_write_to
        (__synapse_structure_spsc_queue*, 
         __synapse_structure_spsc_queue_probe*, void*, size_t);

void
    __synapse_structure_spsc_queue_write_to_until_success
        (__synapse_structure_spsc_queue*, 
         __synapse_structure_spsc_queue_probe*, void*, size_t);