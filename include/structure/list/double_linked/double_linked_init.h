#pragma once
#include <structure/list/double_linked/double_linked_type.h>
#include <synapse/memory/interface/memory_manager.h>

synapse_structure_double_linked
	synapse_structure_double_linked_initialize
		(synapse_memory_manager*);

void
	synapse_structure_double_linked_cleanup
		(synapse_structure_double_linked);