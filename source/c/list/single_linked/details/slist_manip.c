#include <structure/details/list/single_linked/slist_manip.h>
#include <structure/details/list/single_linked/slist_init.h>

#include <stdbool.h>
#include <Windows.h>

void
	__synapse_structure_slist_push
		(__synapse_structure_slist_head* pList, void* pData, size_t pDataSize)
{
	__synapse_structure_slist_node*
		ptr_node
			= __synapse_structure_slist_node_initialize
					(pList, pData, pDataSize);

	while 
		(InterlockedCompareExchange64
			(&pList->entry, ptr_node, pList->entry)
				== ptr_node);
}

void*
	__synapse_structure_slist_pop
		(__synapse_structure_slist_head* pList)
{
	__synapse_structure_slist_node*
		ptr_pop = NULL;
	void*
		ptr_pop_data = NULL;

	if(!pList->entry)
		return NULL;
	
	do
	{
		ptr_pop
			= pList->entry;
	} while 
		(InterlockedCompareExchange64
			(&pList->entry, pList->entry->node_next, pList->entry)
				== pList->entry->node_next);

	ptr_pop_data
		= ptr_pop->data_ptr;
	__synapse_structure_slist_node_cleanup
		(pList, ptr_pop);

	return
		ptr_pop_data;
}

__synapse_structure_slist_node* 
	__synapse_structure_slist_peek
		(__synapse_structure_slist_head* pList)
{
	return
		pList->entry;
}