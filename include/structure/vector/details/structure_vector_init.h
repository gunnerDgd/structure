#pragma once
#include <structure/vector/details/structure_vector_type.h>

__synapse_structure_vector*
	__synapse_structure_vector_initialize
		(synapse_memory_mman_traits*);

void
	__synapse_structure_vector_cleanup
		(__synapse_structure_vector*);