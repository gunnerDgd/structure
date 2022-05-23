#include <structure/details/list/single_linked/slist_manip.h>
#include <Windows.h>

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_back(__synapse_structure_slist_head* pHead, void* pData, size_t pSize)
{
	__synapse_structure_slist_node* ptr_node 
		= __synapse_structure_slist_mman_allocate(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));

	ptr_node->parent_head = pHead;
	ptr_node->data_ptr 
		= __synapse_structure_slist_mman_allocate (pHead->mman, NULL, pSize);
		  __synapse_structure_slist_mman_copy_from(pHead->mman, ptr_node->data_ptr, pData, pSize);

	pHead->back->next = ptr_node;
	pHead->back		  = ptr_node;
	
	InterlockedIncrement(&pHead->node_count);
	return ptr_node;
}

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_front(__synapse_structure_slist_head* pHead, void* pData, size_t pSize)
{
	__synapse_structure_slist_node* ptr_node 
		= __synapse_structure_slist_mman_allocate(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));

	ptr_node->parent_head = pHead;
	ptr_node->data_ptr 
		= __synapse_structure_slist_mman_allocate (pHead->mman, NULL, pSize);
		  __synapse_structure_slist_mman_copy_from(pHead->mman, ptr_node->data_ptr, pData, pSize);

	ptr_node->next = pHead->front;
	pHead->front   = ptr_node;
	
	InterlockedIncrement(&pHead->node_count);
	return ptr_node;
}

__synapse_structure_slist_node* 
__synapse_structure_slist_insert_at(__synapse_structure_slist_head* pHead, void* pData, size_t pSize, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_at(pHead, pIndex),
								  * ptr_insert
		= __synapse_structure_slist_mman_allocate(pHead->mman, NULL, sizeof(__synapse_structure_slist_node));

	ptr_insert->data_ptr
		= __synapse_structure_slist_mman_allocate(pHead->mman, NULL, pSize);
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
		= __synapse_structure_slist_retrive_front(pHead);

	for( ; ptr_seek->next->next ; 
		   ptr_seek = ptr_seek->next);

	pHead->back = ptr_seek;
	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_seek->next->data_ptr, ptr_seek->next->data_size)				;
	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_seek->next		   , sizeof(__synapse_structure_slist_node));

	ptr_seek->next = NULL;
}

void __synapse_structure_slist_erase_front(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_front(pHead);

	pHead->front = ptr_node->next;
	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_node->data_ptr, ptr_node->data_size);
	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_node			 , sizeof(__synapse_structure_slist_node));
}

void __synapse_structure_slist_erase_at(__synapse_structure_slist_head* pHead, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_node
		= __synapse_structure_slist_retrive_at(pHead, pIndex - 1),
								  * ptr_new_next;

	if (!ptr_node->next) return;
	ptr_new_next = ptr_node->next->next;

	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_node->next->data_ptr, ptr_node->data_size);
	__synapse_structure_slist_mman_deallocate(pHead->mman, ptr_node->next		   , sizeof(__synapse_structure_slist_node));

	ptr_node->next = ptr_new_next;
}

__synapse_structure_slist_node* __synapse_structure_slist_retrive_at(__synapse_structure_slist_head* pHead, size_t pIndex)
{
	__synapse_structure_slist_node* ptr_seek
		= __synapse_structure_slist_retrive_front(pHead);

	for (; ptr_seek->next && pIndex >= 0; ptr_seek = ptr_seek->next, pIndex--);
	return ptr_seek;
}