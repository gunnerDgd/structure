#pragma once
#include <structure/list/single_linked/single_linked_type.h>

synapse_structure_single_linked
	synapse_structure_single_linked_initialize
		(synapse_memory_manager*);

void
	synapse_structure_single_linked_cleanup
		(synapse_structure_single_linked);

void
	synapse_structure_single_linked_node_cleanup
		(synapse_structure_single_linked, synapse_structure_single_linked_node);