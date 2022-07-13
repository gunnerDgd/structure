#pragma once
#include <structure/details/list/double_linked/dlist_types.h>

// Insert Operation.
__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_front
	(__synapse_structure_dlist_head*, void*, size_t);

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_back
	(__synapse_structure_dlist_head*, void*, size_t);

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_at
	(__synapse_structure_dlist_head*, __synapse_structure_dlist_node*, void*, size_t);

void
__synapse_structure_dlist_erase_front
	(__synapse_structure_dlist_head*);

void
__synapse_structure_dlist_erase_back
	(__synapse_structure_dlist_head*);

void
__synapse_structure_dlist_erase_at
	(__synapse_structure_dlist_head*, __synapse_structure_dlist_node*);