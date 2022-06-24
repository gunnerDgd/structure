#pragma once
#include <structure/details/queue/linear/lqueue_init.h>
#include <stdlib.h>

__synapse_structure_lqueue_head*
__synapse_structure_lqueue_initialize
	(synapse_memory_mman_traits* pMman)
{
	__synapse_structure_lqueue_head* ptr_head
		= malloc(sizeof(__synapse_structure_lqueue_head));
	
	ptr_head->ptr_mman	= pMman;
	ptr_head->frontmost = NULL;
	ptr_head->backmost  = NULL;
	ptr_head->count		= 0   ;

	return ptr_head;
}

void
__synapse_structure_lqueue_cleanup(__synapse_structure_lqueue_head* pHead)
{
	__synapse_structure_lqueue_node* ptr_seek
		= pHead->backmost;
	
	for (; ptr_seek; ptr_seek = ptr_seek->prev)
	{
		if (ptr_seek->next) 
			synapse_memory_mman_traits_deallocate
				(pHead->ptr_mman, ptr_seek->next, sizeof(__synapse_structure_lqueue_node));
		
		synapse_memory_mman_traits_deallocate
			(pHead->ptr_mman, ptr_seek->ptr_entity, ptr_seek->size_entity);
	}

	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, pHead->frontmost->ptr_entity, pHead->frontmost->size_entity);
	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, pHead->frontmost, sizeof(__synapse_structure_lqueue_node));

	free(pHead);
}