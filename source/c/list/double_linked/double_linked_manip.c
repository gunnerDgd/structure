#include <structure/list/double_linked/double_linked_manip.h>
#include <structure/details/list/double_linked/dlist_manip.h>

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_front
	(synapse_structure_double_linked pDoubleLinked, void* pData, size_t pDataSize)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque 
				= __synapse_structure_dlist_insert_front
						(pDoubleLinked.opaque, pData, pDataSize) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_back
	(synapse_structure_double_linked pDoubleLinked, void* pData, size_t pDataSize)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque 
				= __synapse_structure_dlist_insert_back
						(pDoubleLinked.opaque, pData, pDataSize) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_at
	(synapse_structure_double_linked	  pDoubleLinked, 
	 synapse_structure_double_linked_node pNode,
	 void*								  pData, 
	 size_t								  pDataSize)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque 
				= __synapse_structure_dlist_insert_at
						(pDoubleLinked.opaque, pNode.opaque, pData, pDataSize) };

	return ptr_node;
}

void
synapse_structure_double_linked_erase_front
	(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_erase_front
		(pDoubleLinked.opaque);
}

void
synapse_structure_double_linked_erase_back
	(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_erase_back
		(pDoubleLinked.opaque);
}

void
synapse_structure_double_linked_erase_at
	(synapse_structure_double_linked pDoubleLinked, synapse_structure_double_linked_node pNode)
{
	__synapse_structure_dlist_erase_at
		(pDoubleLinked.opaque, pNode.opaque);
}