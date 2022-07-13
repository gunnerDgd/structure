#pragma once
#include <structure/details/queue/circular/cqueue_types.h>

void
	__synapse_structure_cqueue_read_from
		(__synapse_structure_cqueue_head*, void*, size_t);

void
	__synapse_structure_cqueue_write_to 
		(__synapse_structure_cqueue_head*, void*, size_t);

__synapse_structure_cqueue_node*
	__synapse_structure_cqueue_rdptr
		(__synapse_structure_cqueue_head*);

__synapse_structure_cqueue_node*
	__synapse_structure_cqueue_wrptr
		(__synapse_structure_cqueue_head*);