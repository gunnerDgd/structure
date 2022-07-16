#pragma once
#include <structure/list/single_linked/single_linked_type.h>


void
    synapse_structure_single_linked_push
        (synapse_structure_single_linked, void*, size_t);

synapse_structure_single_linked_node
    synapse_structure_single_linked_pop
        (synapse_structure_single_linked);

synapse_structure_single_linked_node
    synapse_structure_single_linked_pop_until_success
        (synapse_structure_single_linked);

synapse_structure_single_linked_node
    synapse_structure_single_linked_peek
        (synapse_structure_single_linked);