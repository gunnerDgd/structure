#include <structure/details/list/double_linked/dlist_manip.h>
#include <Windows.h>

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_front(__synapse_structure_dlist_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_node* ptr_node
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, sizeof(__synapse_structure_dlist_node));

	ptr_node->next = pHead->entry;
	ptr_node->prev = NULL		 ;

	ptr_node->node_size = pDataSize;
	ptr_node->node_ptr  = synapse_memory_mman_traits_allocate(pHead->mman, NULL, pDataSize);

	memcpy				(ptr_node->node_ptr, pData, pDataSize);
	InterlockedIncrement(&pHead->node_count);

						  pHead->entry    = ptr_node;
	if (!pHead->backmost) pHead->backmost = ptr_node;
	return									ptr_node;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_back(__synapse_structure_dlist_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_node* ptr_node
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, sizeof(__synapse_structure_dlist_node));

	ptr_node->next = NULL;
	ptr_node->prev = pHead->backmost;

	ptr_node->node_size = pDataSize;
	ptr_node->node_ptr  = synapse_memory_mman_traits_allocate(pHead->mman, NULL, pDataSize);

	memcpy				(ptr_node->node_ptr, pData, pDataSize);
	InterlockedIncrement(&pHead->node_count);

	if(pHead->backmost) pHead->backmost->next = ptr_node;
					    pHead->backmost		  = ptr_node;
	if (!pHead->entry)  pHead->entry		  = ptr_node;
	return									    ptr_node;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_at(__synapse_structure_dlist_head* pHead, void* pData, size_t pDataSize, size_t pIndex)
{
	__synapse_structure_dlist_node* ptr_seek
		= __synapse_structure_dlist_retrieve_at(pHead, pIndex),
								  * ptr_node;

	if (!ptr_seek)
		return __synapse_structure_dlist_insert_back (pHead, pData, pDataSize);
	
	ptr_node
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, sizeof(__synapse_structure_dlist_node));
	ptr_node->node_ptr
		= synapse_memory_mman_traits_allocate(pHead->mman, NULL, pDataSize);
	
	ptr_node->next = ptr_seek->next;
	ptr_node->prev = ptr_seek;

	memcpy				(ptr_node->node_ptr, pData, pDataSize);
	InterlockedIncrement(&pHead->node_count);

						ptr_seek->next		 = ptr_node;
	if (ptr_seek->next) ptr_seek->next->prev = ptr_node;

	return									   ptr_node;
}

void
__synapse_structure_dlist_erase_front(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node* ptr_erase
		= pHead->entry;

	if (!ptr_erase) return;

	pHead->entry = ptr_erase->next;
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase->node_ptr, ptr_erase->node_size);
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase		  , sizeof(__synapse_structure_dlist_node));

	InterlockedDecrement(&pHead->node_count);
}

void
__synapse_structure_dlist_erase_back(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node* ptr_erase
		= pHead->backmost;

	if (!ptr_erase) return;

	pHead->backmost = ptr_erase->prev;
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase->node_ptr, ptr_erase->node_size);
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase		  , sizeof(__synapse_structure_dlist_node));

	InterlockedDecrement(&pHead->node_count);
}

void
__synapse_structure_dlist_erase_at(__synapse_structure_dlist_head* pHead, size_t pIndex)
{
	__synapse_structure_dlist_node* ptr_erase
		= __synapse_structure_dlist_retrieve_at(pHead, pIndex);

	if (!ptr_erase) return;

	if (ptr_erase->prev) ptr_erase->prev->next = ptr_erase->next; else { pHead->entry	 = ptr_erase->next; }
	if (ptr_erase->next) ptr_erase->next->prev = ptr_erase->prev; else { pHead->backmost = ptr_erase->prev; }

	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase->node_ptr, ptr_erase->node_size);
	synapse_memory_mman_traits_deallocate
		(pHead->mman, ptr_erase, sizeof(__synapse_structure_dlist_node));

	InterlockedDecrement(&pHead->node_count);
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_retrieve_at(__synapse_structure_dlist_head* pHead, size_t pIndex)
{
	__synapse_structure_dlist_node* ptr_seek
		= pHead->entry;

	for( ; ptr_seek && ptr_seek->next && pIndex 
		 ; ptr_seek  = ptr_seek->next, --pIndex);

	return ptr_seek;
}