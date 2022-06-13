#pragma once
#include <structure/details/queue/linear/lqueue_init.h>
#include <stdlib.h>

__synapse_structure_lqueue_head*
__synapse_structure_lqueue_initialize(synapse_structure_mman pMman)
{
	__synapse_structure_lqueue_head* ptr_head
		= malloc(sizeof(__synapse_structure_lqueue_head));
	
	ptr_head->mman	    = pMman;
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
		if (ptr_seek->next) free(ptr_seek->next);
							free(ptr_seek->ptr_entity);
	}

	free(pHead->frontmost);
	free(pHead);
}