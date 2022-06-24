#pragma once
#include <structure/details/queue/linear/lqueue_types.h>

__synapse_structure_lqueue_head*
__synapse_structure_lqueue_initialize
	(synapse_memory_mman_traits*);

void
__synapse_structure_lqueue_cleanup
	(__synapse_structure_lqueue_head*);