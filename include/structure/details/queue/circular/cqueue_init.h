#pragma once
#include <structure/details/queue/circular/cqueue_types.h>

__synapse_structure_cqueue_head*
__synapse_structure_cqueue_initialize
	(synapse_memory_mman_traits*, size_t, size_t);

void
__synapse_structure_cqueue_cleanup
	(__synapse_structure_cqueue_head*);