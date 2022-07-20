#pragma once
#include <structure/details/queue/circular/cqueue_types.h>
#include <stdbool.h>

__synapse_structure_cqueue_node*
	__synapse_structure_cqueue_read_from
		(__synapse_structure_cqueue_head*);

bool
	__synapse_structure_cqueue_write_to
		(__synapse_structure_cqueue_head*, void*, size_t);