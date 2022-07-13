#include <structure/details/list/double_linked/dlist_node.h>

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_at
	(__synapse_structure_dlist_head* pHead, size_t pIndex)
{
	__synapse_structure_dlist_node*
		ptr_seek = pHead->entry;

	if (!ptr_seek)
		return NULL;

	for ( ; ptr_seek->next && pIndex
		  ; ptr_seek = ptr_seek->next, pIndex--);

	return
		ptr_seek;
}

void*
__synapse_structure_dlist_retrieve_node_data_ptr
	(__synapse_structure_dlist_node* pNode)
{
	return
		pNode->node_ptr;
}

size_t
__synapse_structure_dlist_retrieve_node_data_size
	(__synapse_structure_dlist_node* pNode)
{
	return
		pNode->node_size;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_node_next
	(__synapse_structure_dlist_node* pNode)
{
	return
		pNode->next;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_node_prev
	(__synapse_structure_dlist_node* pNode)
{
	return
		pNode->prev;
}

void
__synapse_structure_dlist_assign_node_data
	(__synapse_structure_dlist_node* pNode, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_head*
		pHead
			= pNode->node_head;

	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->mblock_data_ptr);
	pNode->mblock_data_ptr
		= pHead->mman->allocate
			(pHead->mman->hnd_mman, NULL, pDataSize);
	
	pNode->node_ptr
		= pHead->mman->block_pointer
			(pNode->mblock_data_ptr);
	pNode->node_size
		= pDataSize;

	memcpy
		(pNode->node_ptr, pData, pDataSize);
}