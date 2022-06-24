#include <structure/details/queue/linear/lqueue_types.h>

#include <stdlib.h>
#include <string.h>

void
__synapse_structure_lqueue_push_back
	(__synapse_structure_lqueue_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_node* ptr_node
		= synapse_memory_mman_traits_allocate
			(pHead->ptr_mman, NULL, sizeof(__synapse_structure_lqueue_node));

	ptr_node->ptr_entity  
		= synapse_memory_mman_traits_allocate
			(pHead->ptr_mman, NULL, pDataSize);
	ptr_node->size_entity 
		= pDataSize;

	memcpy(ptr_node->ptr_entity, pData, pDataSize);

	if (!pHead->frontmost) pHead->frontmost = ptr_node;
											  ptr_node->next = NULL;
											  ptr_node->prev = pHead->backmost;

	if (pHead->backmost) pHead->backmost->next = ptr_node;
					     pHead->backmost	   = ptr_node;
}

void
__synapse_structure_lqueue_push_front
	(__synapse_structure_lqueue_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_node* ptr_node
		= synapse_memory_mman_traits_allocate
			(pHead->ptr_mman, NULL, sizeof(__synapse_structure_lqueue_node));

	ptr_node->ptr_entity  
		= synapse_memory_mman_traits_allocate
			(pHead->ptr_mman, NULL, pDataSize);
	ptr_node->size_entity 
		= pDataSize;

	memcpy(ptr_node->ptr_entity, pData, pDataSize);

	if (!pHead->backmost) pHead->backmost = ptr_node;
											ptr_node->prev = NULL;
											ptr_node->next = pHead->frontmost;
	
	if (pHead->frontmost) pHead->frontmost->prev = ptr_node;
						  pHead->frontmost		 = ptr_node;
}

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_front
	(__synapse_structure_lqueue_head* pHead) { return pHead->frontmost; }

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_back 
	(__synapse_structure_lqueue_head* pHead) { return pHead->backmost ; }

void
__synapse_structure_lqueue_push_back_node
	(__synapse_structure_lqueue_head* pHead, __synapse_structure_lqueue_node* pNode)
{
	if (pNode->prev) pNode->prev->next = pNode->next;
	if (pNode->next) pNode->next->prev = pNode->prev;

	pHead->backmost->next = pNode;
	pNode->prev		      = pHead->backmost;
	pHead->backmost       = pNode;
}

void
__synapse_structure_lqueue_push_front_node
	(__synapse_structure_lqueue_head* pHead, __synapse_structure_lqueue_node* pNode)
{
	if (pNode->prev) pNode->prev->next = pNode->next;
	if (pNode->next) pNode->next->prev = pNode->prev;

	pHead->frontmost->prev = pNode;
	pNode->next			   = pHead->frontmost;
	pHead->frontmost	   = pNode;
}

void
__synapse_structure_lqueue_pop_back
	(__synapse_structure_lqueue_head* pHead)
{
	__synapse_structure_lqueue_node* ptr_backmost
		= pHead->backmost;

	if (!ptr_backmost) return;
	pHead->backmost = ptr_backmost->prev;
	
	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, ptr_backmost->ptr_entity, ptr_backmost->size_entity);
	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, ptr_backmost, sizeof(__synapse_structure_lqueue_node));
}

void
__synapse_structure_lqueue_pop_front
	(__synapse_structure_lqueue_head* pHead)
{
	__synapse_structure_lqueue_node* ptr_frontmost
		= pHead->frontmost;

	if (!ptr_frontmost) return;
	pHead->frontmost = ptr_frontmost->next;
	
	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, ptr_frontmost->ptr_entity, ptr_frontmost->size_entity);
	synapse_memory_mman_traits_deallocate
		(pHead->ptr_mman, ptr_frontmost, sizeof(__synapse_structure_lqueue_node));
}