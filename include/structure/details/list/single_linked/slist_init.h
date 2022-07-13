#pragma once
#include <structure/details/list/single_linked/slist_types.h>

__synapse_structure_slist_head* 
	__synapse_structure_slist_initialize 
		(synapse_memory_mman_traits*);

__synapse_structure_slist_node*
	__synapse_structure_slist_node_initialize
		(__synapse_structure_slist_head*, void*, size_t);

void
	__synapse_structure_slist_cleanup 
		(__synapse_structure_slist_head*);

void
	__synapse_structure_slist_node_cleanup
		(__synapse_structure_slist_head*, __synapse_structure_slist_node*);

long
	__synapse_structure_slist_reference  
		(__synapse_structure_slist_head*);

long
	__synapse_structure_slist_dereference
		(__synapse_structure_slist_head*);