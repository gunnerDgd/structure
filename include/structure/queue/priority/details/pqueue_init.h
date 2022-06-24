#pragma once
#include <structure/queue/priority/details/pqueue_type.h>

__synapse_structure_pqueue_head*
__synapse_structure_pqueue_initialize
	(synapse_memory_mman_traits*);

void
__synapse_structure_pqueue_cleanup
	(__synapse_structure_pqueue_head*);