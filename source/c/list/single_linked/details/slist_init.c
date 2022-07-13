#include <structure/details/list/single_linked/slist_init.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_structure_slist_head* 
	__synapse_structure_slist_initialize
		(synapse_memory_mman_traits* pMman)
{
	synapse_memory_mman_block
		hnd_mblock
			= pMman->allocate
					(pMman->hnd_mman, NULL, sizeof(__synapse_structure_slist_head));

	__synapse_structure_slist_head*
		ptr_head
			= pMman->block_pointer
					(hnd_mblock);

	ptr_head->back  = NULL;
	ptr_head->front = NULL;
	
	ptr_head->mman  
		= pMman;
	ptr_head->mman_mblock
		= hnd_mblock;

	ptr_head->slist_node_count
		= 0;
	ptr_head->slist_refcount
		= 0;

	return ptr_head;
}

void 
	__synapse_structure_slist_cleanup
		(__synapse_structure_slist_head* pHead)
{
	if (pHead->slist_refcount) {
		__synapse_structure_slist_dereference
			(pHead);
		return;
	}

	pHead->mman->deallocate_all
		(pHead->mman->hnd_mman);
}

long 
	__synapse_structure_slist_reference
		(__synapse_structure_slist_head* pHead)
{
	return
		InterlockedIncrement
			(&pHead->slist_refcount);
}

long 
	__synapse_structure_slist_dereference
		(__synapse_structure_slist_head* pHead)
{
	if(pHead->slist_refcount)
		InterlockedDecrement
			(&pHead->slist_refcount);
	else
		return 0;
}

__synapse_structure_slist_node*
	__synapse_structure_slist_node_initialize
		(__synapse_structure_slist_head* pHead, void* pData, size_t pDataSize)
{
	synapse_memory_mman_block
		hnd_mblock
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, 
						NULL, sizeof(__synapse_structure_slist_node)),
		hnd_mblock_data
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, NULL, pDataSize);

	__synapse_structure_slist_node*
		ptr_node
			= pHead->mman->block_pointer
					(hnd_mblock);
	
	ptr_node->data_ptr
		= pHead->mman->block_pointer
				(hnd_mblock);
	ptr_node->data_size
		= pDataSize;
	memcpy
		(ptr_node->data_ptr, pData, pDataSize);

	ptr_node->node_mblock
		= hnd_mblock;
	ptr_node->node_data_mblock
		= hnd_mblock_data;
	ptr_node->node_parent
		= pHead;

	return
		ptr_node;
}

void
	__synapse_structure_slist_node_cleanup
		(__synapse_structure_slist_head* pHead, __synapse_structure_slist_node* pNode)
{
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->node_data_mblock);
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->node_mblock);
}