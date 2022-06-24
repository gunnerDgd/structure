#include <structure/details/list/single_linked/slist_init.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_structure_slist_head* 
__synapse_structure_slist_initialize(synapse_memory_mman_traits* pMman)
{
	__synapse_structure_slist_head*
		ptr_head = malloc(sizeof(__synapse_structure_slist_head));

	ptr_head->entry			  = NULL;
	ptr_head->back			  = NULL;
	ptr_head->front			  = NULL;
	ptr_head->mman			  = pMman;

	ptr_head->node_count	  = 0;
	ptr_head->reference_count = 0;

	return ptr_head;
}

void __synapse_structure_slist_destroy(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_node* ptr_node
		= pHead->front;

	while(ptr_node)
	{
		__synapse_structure_slist_node* ptr_next
			= ptr_node->next;

		synapse_memory_mman_traits_deallocate
			(pHead->mman, ptr_node->data_ptr, ptr_node->data_size);
		synapse_memory_mman_traits_deallocate
			(pHead->mman, ptr_node, sizeof(__synapse_structure_slist_node));

		ptr_node = ptr_next;
	}

	free(pHead);
}

long __synapse_structure_slist_reference(__synapse_structure_slist_head* pHead)
{
	InterlockedIncrement(&pHead->reference_count);
	return				  pHead->reference_count ;
}

long __synapse_structure_slist_dereference(__synapse_structure_slist_head* pHead)
{
	if(pHead->reference_count > 0)
		InterlockedDecrement(&pHead->reference_count);
	return					  pHead->reference_count;
}