#pragma once
#include <structure/queue/priority/details/pqueue_type.h>

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_node_initialize
	(synapse_memory_mman_traits*, __synapse_structure_pqueue_key*, void*, size_t);

void
__synapse_structure_pqueue_node_cleanup
	(synapse_memory_mman_traits*, __synapse_structure_pqueue_node*);