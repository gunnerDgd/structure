#pragma once
#include <structure/details/list/double_linked/dlist_types.h>

__synapse_structure_dlist_head*
	__synapse_structure_dlist_initialize
		(synapse_memory_manager*);

__synapse_structure_dlist_node*
	__synapse_structure_dlist_node_initialize
		(__synapse_structure_dlist_head*, void*, size_t);

void
	__synapse_structure_dlist_cleanup
		(__synapse_structure_dlist_head*);

void
	__synapse_structure_dlist_node_cleanup
		(__synapse_structure_dlist_head*, __synapse_structure_dlist_node*);

void
	__synapse_structure_dlist_reference
		(__synapse_structure_dlist_head*);

void
	__synapse_structure_dlist_dereference
		(__synapse_structure_dlist_head*);