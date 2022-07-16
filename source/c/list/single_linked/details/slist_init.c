#include <structure/details/list/single_linked/slist_init.h>
#include <structure/details/list/single_linked/slist_manip.h>

#include <string.h>

__synapse_structure_slist_head* 
	__synapse_structure_slist_initialize
		(synapse_memory_manager* pMman)
{
	synapse_memory_block
		hnd_mblock
			= pMman->allocate
					(pMman->hnd_mman, 
						NULL, sizeof(__synapse_structure_slist_head));

	__synapse_structure_slist_head*
		ptr_head
			= pMman->block_pointer
						(hnd_mblock);

	ptr_head->entry = NULL;
	
	ptr_head->mman  
		= pMman;
	ptr_head->mman_mblock
		= hnd_mblock;

	return ptr_head;
}

void 
	__synapse_structure_slist_cleanup
		(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_node*
		ptr_erase
			= NULL;
	while
		((ptr_erase
			= __synapse_structure_slist_pop(pHead)))
		__synapse_structure_slist_node_cleanup
			(pHead, ptr_erase);

	pHead->mman->deallocate
		(pHead->mman->hnd_mman,
			pHead->mman_mblock);
}

__synapse_structure_slist_node*
	__synapse_structure_slist_node_initialize
		(__synapse_structure_slist_head* pHead, void* pData, size_t pDataSize)
{
	synapse_memory_block
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
	ptr_node->node_mblock_data
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
		(pHead->mman->hnd_mman, pNode->node_mblock_data);
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->node_mblock);
}