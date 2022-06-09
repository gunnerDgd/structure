#pragma once
#include <structure/list/single_linked_type.h>
#include <structure/mman/mman.h>

void*  synapse_structure_single_linked_node_data(synapse_structure_single_linked_node);
size_t synapse_structure_single_linked_node_size(synapse_structure_single_linked_node);

synapse_structure_single_linked_node
synapse_structure_single_linked_node_next	    (synapse_structure_single_linked_node); // 0 for Success, -1 for fail.