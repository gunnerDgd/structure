#include <structure/details/list/single_linked/slist_manip.h>

#include <Windows.h>

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_back(__synapse_structure_slist_head* pHead, void* pData, size_t pSize)
{
	__synapse_structure_slist_node* ptr_node 
		= synapse_memory_mman_traits_allocate
			(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));
	
	ptr_node->parent_head 
		= pHead;
	ptr_node->data_ptr 
		= synapse_memory_mman_traits_allocate
			(pHead->mman, NULL, pSize);
	ptr_node->next
		= NULL;
	
	memcpy(ptr_node->data_ptr, pData, pSize);

	if(!pHead->front) pHead->front		= ptr_node;
	if(pHead->back)   pHead->back->next = ptr_node;
					  pHead->back		= ptr_node;
	
	InterlockedIncrement(&pHead->node_count);
	return ptr_node;
}

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_front(__synapse_structure_slist_head* pHead, void* pData, size_t pSize)
{
	__synapse_structure_slist_node* ptr_node 
		= synapse_memory_mman_traits_allocate
			(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));

	ptr_node->parent_head = pHead;
	ptr_node->data_ptr 
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, pSize);
	
	memcpy(ptr_node->data_ptr, pData, pSize);

	ptr_node->next  = pHead->front;
	if (pHead->front) pHead->front = ptr_node;
	if (!pHead->back) pHead->back  = ptr_node;
	
	InterlockedIncrement(&pHead->node_count);
	return ptr_node;
}

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_at(__synapse_structure_slist_head* pHead, void* pData, size_t pSize, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_at(pHead, pIndex),
								  * ptr_insert
		= synapse_memory_mman_traits_allocate
			(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));

	ptr_insert->data_ptr
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, pSize);
	ptr_insert->data_size   = pSize;
	ptr_insert->parent_head = pHead;

	ptr_insert->next = ptr_node->next;
	ptr_node  ->next = ptr_insert;

	InterlockedIncrement(&pHead->node_count);
	return ptr_insert;
}

void __synapse_structure_slist_erase_back(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_node* ptr_seek
		= __synapse_structure_slist_retrive_back(pHead);

	if (!ptr_seek) return;

	for( ; ptr_seek->next && ptr_seek->next->next; 
		   ptr_seek		   = ptr_seek->next);

	pHead->back = ptr_seek;
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_seek->next->data_ptr, ptr_seek->next->data_size)				;
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_seek->next, sizeof(__synapse_structure_slist_node));

	ptr_seek->next = NULL;
}

void __synapse_structure_slist_erase_front(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_front(pHead);

	if (!ptr_node) return;

	pHead->front = ptr_node->next;
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_node->data_ptr, ptr_node->data_size);
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_node, sizeof(__synapse_structure_slist_node));
}

void __synapse_structure_slist_erase_at(__synapse_structure_slist_head* pHead, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_at(pHead, pIndex - 1),
								  * ptr_new_next;

	if (!ptr_node || !ptr_node->next) return;
	ptr_new_next = ptr_node->next->next;

	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_node->next->data_ptr, ptr_node->data_size);
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_node->next, sizeof(__synapse_structure_slist_node));

	ptr_node->next = ptr_new_next;
}

__synapse_structure_slist_node* __synapse_structure_slist_retrive_at(__synapse_structure_slist_head* pHead, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_seek
		= __synapse_structure_slist_retrive_front(pHead);

	if (!ptr_seek)
		return NULL;

	for (; ptr_seek->next && pIndex > 0; ptr_seek = ptr_seek->next, pIndex--);
	return ptr_seek;
}