#pragma once
#include <structure/queue/priority/details/pqueue_type.h>

__synapse_structure_pqueue_key*
__synapse_structure_pqueue_key_initialize
	(synapse_memory_mman_traits*, void*, size_t, int(*)(void*, void*));

__synapse_structure_pqueue_key*
__synapse_structure_pqueue_key_initialize_from_existing
	(synapse_memory_mman_traits*, __synapse_structure_pqueue_key*);

void
__synapse_structure_pqueue_key_cleanup
	(synapse_memory_mman_traits*, __synapse_structure_pqueue_key*);