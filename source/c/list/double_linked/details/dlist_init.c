#include <structure/details/list/double_linked/dlist_init.h>
#include <Windows.h>

__synapse_structure_dlist_head*
	__synapse_structure_dlist_initialize
		(synapse_memory_manager* pMman)
{
	synapse_memory_block
		hnd_dlist_mblock 
			= pMman->allocate
					(pMman->hnd_mman,
							NULL, sizeof(__synapse_structure_dlist_head));

	__synapse_structure_dlist_head*
		ptr_dlist
			= pMman->block_pointer
					(hnd_dlist_mblock);
	

	ptr_dlist->mman			   = pMman;
	ptr_dlist->backmost		   = NULL  ;
	ptr_dlist->entry		   = NULL  ;

	ptr_dlist->node_count      = 0;
	ptr_dlist->reference_count = 1;

	return ptr_dlist;
}

void
	__synapse_structure_dlist_cleanup
		(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node*
		ptr_node
			= pHead->entry;

	if (pHead->reference_count) {
	__synapse_structure_dlist_dereference
		(pHead);

		return;
	}

	while (ptr_node)
	{
		__synapse_structure_dlist_node*
			ptr_dealloc
				= ptr_node;

		ptr_node
			= ptr_node->next;

		pHead->mman->deallocate
			(pHead->mman->hnd_mman, ptr_dealloc->mblock_data_ptr);
		pHead->mman->deallocate
			(pHead->mman->hnd_mman, ptr_dealloc->mblock_node_ptr);
	}

	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pHead->hnd_mblock);
}

void
__synapse_structure_dlist_reference
	(__synapse_structure_dlist_head* pHead)
{
	InterlockedIncrement
		(&pHead->reference_count);
}

void
__synapse_structure_dlist_dereference
	(__synapse_structure_dlist_head* pHead)
{
	if(pHead->reference_count)
		InterlockedDecrement
			(&pHead->reference_count);
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_node_initialize
	(__synapse_structure_dlist_head* pHead, void* pDataPtr, size_t pDataSize)
{
	synapse_memory_block
		hnd_mblock_node
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, NULL, sizeof(__synapse_structure_dlist_node)),
		hnd_mblock_data
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, NULL, pDataSize);

	__synapse_structure_dlist_node*
		ptr_node
			= pHead->mman->block_pointer
					(hnd_mblock_node);

	ptr_node->mblock_node_ptr
		= hnd_mblock_node;
	ptr_node->mblock_data_ptr
		= hnd_mblock_data;
	ptr_node->node_head
		= pHead;

	ptr_node->node_ptr
		= pHead->mman->block_pointer
				(hnd_mblock_data);
	ptr_node->node_size
		= pDataSize;

	memcpy
		(ptr_node->node_ptr, pDataPtr, pDataSize);

	return ptr_node;
}

void
__synapse_structure_dlist_node_cleanup
	(__synapse_structure_dlist_head* pHead, __synapse_structure_dlist_node* pNode)
{
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->mblock_data_ptr);
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->mblock_node_ptr);
}