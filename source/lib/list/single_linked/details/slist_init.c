#include <structure/details/list/single_linked/slist_init.h>
#include <structure/details/list/single_linked/slist_manip.h>

#include <synapse/memory/memory.h>
#include <string.h>


__synapse_structure_slist_head* 
	__synapse_structure_slist_initialize
		(synapse_memory_manager* pMman)
{
	__synapse_structure_slist_head*
		ptr_head;

	if(!pMman)
		pMman = synapse_system_memory_manager();

	ptr_head
		= synapse_system_allocate
				(sizeof(__synapse_structure_slist_head));

	ptr_head->entry = NULL;
	ptr_head->mman  = pMman;

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

	synapse_system_deallocate
		(pHead);
}

__synapse_structure_slist_node*
	__synapse_structure_slist_node_initialize
		(__synapse_structure_slist_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_slist_node*
		ptr_node
			= pHead->mman->allocate
					(pHead->mman->hnd_mman, 
						NULL, sizeof(__synapse_structure_slist_node));
		
	ptr_node->data_ptr
		= pHead->mman->allocate
				(pHead->mman->hnd_mman, NULL, pDataSize);
	ptr_node->data_size
		= pDataSize;
	memcpy
		(ptr_node->data_ptr, pData, pDataSize);
	
	ptr_node->node_parent
		= pHead;
	ptr_node->node_next
		= NULL;

	return
		ptr_node;
}

void
	__synapse_structure_slist_node_cleanup
		(__synapse_structure_slist_head* pHead, __synapse_structure_slist_node* pNode)
{
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode->data_ptr);
	pHead->mman->deallocate
		(pHead->mman->hnd_mman, pNode);
}