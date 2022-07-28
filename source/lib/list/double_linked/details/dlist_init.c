#include <structure/details/list/double_linked/dlist_init.h>
#include <Windows.h>

#include <synapse/memory/memory.h>

__synapse_structure_dlist_head*
	__synapse_structure_dlist_initialize
		(synapse_memory_manager* pMman)
{
	__synapse_structure_dlist_head*
		ptr_dlist
			= synapse_system_allocate
				(sizeof(__synapse_structure_dlist_head));

	if(!pMman)	
		pMman = synapse_system_memory_manager();

	ptr_dlist->mman		= pMman;
	ptr_dlist->backmost = NULL  ;
	ptr_dlist->entry	= NULL  ;


	return ptr_dlist;
}

void
	__synapse_structure_dlist_cleanup
		(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node*
		ptr_node
			= pHead->entry;

	while (ptr_node)
	{
		__synapse_structure_dlist_node*
			ptr_dealloc
				= ptr_node;

		ptr_node
			= ptr_node->next;

		pHead->mman->deallocate
			(pHead->mman->hnd_mman, ptr_dealloc->node_ptr);
		pHead->mman->deallocate
			(pHead->mman->hnd_mman, ptr_dealloc);
	}

	synapse_system_deallocate
		(pHead);
}


__synapse_structure_dlist_node*
	__synapse_structure_dlist_node_initialize
		(__synapse_structure_dlist_head* pHead, void* pDataPtr, size_t pDataSize)
{
	__synapse_structure_dlist_node*
		ptr_node
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, NULL, sizeof(__synapse_structure_dlist_node));
	
	ptr_node->node_ptr
		= pHead->mman->allocate
				(pHead->mman->hnd_mman, NULL, pDataSize);

	ptr_node->node_head
		= pHead;
	ptr_node->node_size
		= pDataSize;

	memcpy
		(ptr_node->node_ptr, pDataPtr, pDataSize);

	return ptr_node;
}

void
	__synapse_structure_dlist_node_cleanup
		(__synapse_structure_dlist_head* pHead, 
		 __synapse_structure_dlist_node* pNode)
{
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->node_ptr);
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode);
}