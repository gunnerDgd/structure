#pragma once
#include <structure/details/list/single_linked/slist_types.h>

void 
	__synapse_structure_slist_push
		(__synapse_structure_slist_head*, void*, size_t);

void*
	__synapse_structure_slist_pop
		(__synapse_structure_slist_head*);

__synapse_structure_slist_node* 
	__synapse_structure_slist_peek
		(__synapse_structure_slist_head*);