#include <structure/details/list/double_linked/dlist_types.h>

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_at
	(__synapse_structure_dlist_head*, size_t);

void*
__synapse_structure_dlist_retrieve_node_data_ptr
	(__synapse_structure_dlist_node*);

size_t
__synapse_structure_dlist_retrieve_node_data_size
	(__synapse_structure_dlist_node*);

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_node_next
	(__synapse_structure_dlist_node*);

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_node_prev
	(__synapse_structure_dlist_node*);

void
__synapse_structure_dlist_assign_node_data
	(__synapse_structure_dlist_node*, void*, size_t);