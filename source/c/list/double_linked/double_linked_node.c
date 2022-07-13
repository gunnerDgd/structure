#include <structure/list/double_linked/double_linked_node.h>
#include <structure/details/list/double_linked/dlist_node.h>

synapse_structure_double_linked_node
synapse_structure_double_linked_retrieve_at
	(synapse_structure_double_linked pDoubleLinked, size_t pIndex)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque = 
				__synapse_structure_dlist_retrieve_at
						(pDoubleLinked.opaque, pIndex) };

	return ptr_node;
}

void*
synapse_structure_double_linked_node_data
	(synapse_structure_double_linked_node pNode)
{
	return
		__synapse_structure_dlist_retrieve_node_data_ptr
			(pNode.opaque);
}

size_t
synapse_structure_double_linked_node_size
	(synapse_structure_double_linked_node pNode)
{
	return
		__synapse_structure_dlist_retrieve_node_data_size
			(pNode.opaque);
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_next
	(synapse_structure_double_linked_node pNode)
{
	synapse_structure_double_linked_node ptr_node =
		{ .opaque 
			= __synapse_structure_dlist_retrieve_node_next
					(pNode.opaque) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_prev
	(synapse_structure_double_linked_node pNode)
{
	synapse_structure_double_linked_node ptr_node =
		{ .opaque 
			= __synapse_structure_dlist_retrieve_node_prev
				(pNode.opaque) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_begin
	(synapse_structure_double_linked pDoubleLinked)
{
	synapse_structure_double_linked_node ptr_begin =
		{ .opaque 
			= ((__synapse_structure_dlist_head*)pDoubleLinked.opaque)
					->entry };

	return ptr_begin;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_end
	(synapse_structure_double_linked pDoubleLinked)
{
	synapse_structure_double_linked_node ptr_begin =
		{ .opaque 
			= ((__synapse_structure_dlist_head*)pDoubleLinked.opaque)
					->backmost };

	return ptr_begin;
}