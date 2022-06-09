#include <structure/list/double_linked.h>
#include <structure/details/list/double_linked/dlist_init.h>
#include <structure/details/list/double_linked/dlist_manip.h>

synapse_structure_double_linked
synapse_structure_double_linked_initialize(synapse_structure_mman pMman)
{
	synapse_structure_double_linked ptr_dlist = 
		{ .opaque = __synapse_structure_dlist_initialize(pMman) };

	return ptr_dlist;
}

synapse_structure_double_linked
synapse_structure_double_linked_initialize_default()
{
	synapse_structure_double_linked ptr_dlist = 
		{ .opaque = __synapse_structure_dlist_initialize_default() };

	return ptr_dlist;
}

void
synapse_structure_double_linked_cleanup(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_cleanup(pDoubleLinked.opaque);
}

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_front(synapse_structure_double_linked pDoubleLinked, void* pData, size_t pDataSize)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque = __synapse_structure_dlist_insert_front(pDoubleLinked.opaque, pData, pDataSize) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_back(synapse_structure_double_linked pDoubleLinked, void* pData, size_t pDataSize)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque = __synapse_structure_dlist_insert_back(pDoubleLinked.opaque, pData, pDataSize) };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_insert_at(synapse_structure_double_linked pDoubleLinked, void* pData, size_t pDataSize, size_t pIndex)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque = __synapse_structure_dlist_insert_at(pDoubleLinked.opaque, pData, pDataSize, pIndex) };

	return ptr_node;
}

void
synapse_structure_double_linked_erase_front(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_erase_front(pDoubleLinked.opaque);
}

void
synapse_structure_double_linked_erase_back(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_erase_back(pDoubleLinked.opaque);
}

void
synapse_structure_double_linked_erase_at(synapse_structure_double_linked pDoubleLinked, size_t pIndex)
{
	__synapse_structure_dlist_erase_at(pDoubleLinked.opaque, pIndex);
}

synapse_structure_double_linked_node
synapse_structure_double_linked_retrieve_at(synapse_structure_double_linked pDoubleLinked, size_t pIndex)
{
	synapse_structure_double_linked_node ptr_node
		= { .opaque = __synapse_structure_dlist_retrieve_at(pDoubleLinked.opaque, pIndex) };

	return ptr_node;
}

void*
synapse_structure_double_linked_node_data(synapse_structure_double_linked_node pNode)
{
	return ((__synapse_structure_dlist_node*)pNode.opaque)->node_ptr;
}

size_t
synapse_structure_double_linked_node_size(synapse_structure_double_linked_node pNode)
{
	return ((__synapse_structure_dlist_node*)pNode.opaque)->node_size;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_next(synapse_structure_double_linked_node pNode)
{
	synapse_structure_double_linked_node ptr_node =
		{.opaque = ((__synapse_structure_dlist_node*)pNode.opaque)->next };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_prev(synapse_structure_double_linked_node pNode)
{
	synapse_structure_double_linked_node ptr_node =
		{.opaque = ((__synapse_structure_dlist_node*)pNode.opaque)->prev };

	return ptr_node;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_begin(synapse_structure_double_linked pDoubleLinked)
{
	synapse_structure_double_linked_node ptr_begin =
		{ .opaque = ((__synapse_structure_dlist_head*)pDoubleLinked.opaque)->entry };

	return ptr_begin;
}

synapse_structure_double_linked_node
synapse_structure_double_linked_node_end(synapse_structure_double_linked pDoubleLinked)
{
	synapse_structure_double_linked_node ptr_begin =
		{ .opaque = ((__synapse_structure_dlist_head*)pDoubleLinked.opaque)->backmost };

	return ptr_begin;
}