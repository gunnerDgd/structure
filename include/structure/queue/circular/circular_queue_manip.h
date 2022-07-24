#pragma once
#include <structure/queue/circular/circular_queue_types.h>
#include <stdbool.h>

void*
    synapse_structure_circular_queue_read_from
        (synapse_structure_circular_queue);

void*
    synapse_structure_circular_queue_read_from_until_success
        (synapse_structure_circular_queue);

bool
    synapse_structure_circular_queue_write_to 
        (synapse_structure_circular_queue, void*, size_t);

void
    synapse_structure_circular_queue_write_to_until_success
        (synapse_structure_circular_queue, void*, size_t);