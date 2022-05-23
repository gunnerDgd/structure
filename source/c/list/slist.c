#include <structure/list/single_linked.h>

#include <structure/details/list/single_linked/slist_init.h>
#include <structure/details/list/single_linked/slist_manip.h>

synapse_structure_single_linked
synapse_structure_single_linked_initialize(synapse_structure_single_linked_mman pMman)
{
	synapse_structure_single_linked val_slist
		= { .opaque = __synapse_structure_slist_initialize(&pMman) };

	return val_slist;
}

synapse_structure_single_linked
synapse_structure_single_linked_initialize_default()
{
	synapse_structure_single_linked_mman mman_empty
		= {
			.allocate   = 0,
			.deallocate = 0,
			.resize		= 0,

			.copy_from  = 0,
			.copy_to    = 0
		  };

	synapse_structure_single_linked val_slist
		= { .opaque = __synapse_structure_slist_initialize(&mman_empty) };

	return val_slist;
}

void
synapse_structure_single_linked_destroy(synapse_structure_single_linked pSlist)
{
	__synapse_structure_slist_destroy(pSlist.opaque);
}

synapse_structure_single_linked_node
synapse_structure_single_linked_insert_at(synapse_structure_single_linked pSlist, void* pData, size_t pSize, size_t pIndex)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_insert_at(pSlist.opaque, pData, pSize, pIndex) };

	return val_node;
}

synapse_structure_single_linked_node
synapse_structure_single_linked_insert_front(synapse_structure_single_linked pSlist, void* pData, size_t pSize)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_insert_front(pSlist.opaque, pData, pSize) };

	return val_node;
}

synapse_structure_single_linked_node
synapse_structure_single_linked_insert_back(synapse_structure_single_linked pSlist, void* pData, size_t pSize)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_insert_back(pSlist.opaque, pData, pSize) };

	return val_node;
}

void synapse_structure_single_linked_erase_at(synapse_structure_single_linked pSlist, size_t pIndex)
{
	__synapse_structure_slist_erase_at(pSlist.opaque, pIndex);
}

void synapse_structure_single_linked_erase_back(synapse_structure_single_linked pSlist)
{
	__synapse_structure_slist_erase_back(pSlist.opaque);
}

void synapse_structure_single_linked_erase_front(synapse_structure_single_linked pSlist)
{
	__synapse_structure_slist_erase_front(pSlist.opaque);
}

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_front(synapse_structure_single_linked pSlist)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_retrive_front(((__synapse_structure_slist_head*)(pSlist.opaque))) };

	return val_node;
}

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_back(synapse_structure_single_linked pSlist)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_retrive_back(((__synapse_structure_slist_head*)(pSlist.opaque))) };

	return val_node;
}

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_at(synapse_structure_single_linked pSlist, size_t pIndex)
{
	synapse_structure_single_linked_node val_node
		= { .opaque = __synapse_structure_slist_retrive_at(pSlist.opaque, pIndex) };

	return val_node;
}