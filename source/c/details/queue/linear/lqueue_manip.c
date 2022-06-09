#include <structure/details/queue/linear/lqueue_types.h>
#include <stdlib.h>

void
__synapse_structure_lqueue_push_back(__synapse_structure_lqueue_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_node* ptr_node
		= malloc(sizeof(__synapse_structure_lqueue_node));

	ptr_node->ptr_entity  = pData;
	ptr_node->size_entity = pDataSize;

	ptr_node->next = NULL;
	ptr_node->prev = pHead->backmost;
					 pHead->backmost = ptr_node;
}

void
__synapse_structure_lqueue_push_front(__synapse_structure_lqueue_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_node* ptr_node
		= malloc(sizeof(__synapse_structure_lqueue_node));

	ptr_node->ptr_entity  = pData;
	ptr_node->size_entity = pDataSize;

	ptr_node->prev = NULL;
	ptr_node->next = pHead->frontmost;
					 pHead->frontmost = ptr_node;
}

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_front(__synapse_structure_lqueue_head* pHead) { return pHead->frontmost; }

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_back (__synapse_structure_lqueue_head* pHead) { return pHead->backmost ; }

void
__synapse_structure_lqueue_pop_back(__synapse_structure_lqueue_head* pHead)
{
	__synapse_structure_lqueue_node* ptr_backmost
		= pHead->backmost;

	if (!ptr_backmost) return;
	pHead->backmost = ptr_backmost->prev;
	
	free(ptr_backmost->ptr_entity);
	free(ptr_backmost);
}

void
__synapse_structure_lqueue_pop_front(__synapse_structure_lqueue_head* pHead)
{
	__synapse_structure_lqueue_node* ptr_frontmost
		= pHead->frontmost;

	if (!ptr_frontmost) return;
	pHead->frontmost = ptr_frontmost->next;
	
	free(ptr_frontmost->ptr_entity);
	free(ptr_frontmost);
}