#include <structure/details/list/single_linked/slist_manip.h>
#include <structure/details/list/single_linked/slist_init.h>

#include <stdbool.h>

__synapse_structure_slist_node* 
	__synapse_structure_slist_push
		(__synapse_structure_slist_head* pList, void* pData, size_t pDataSize)
{
	__synapse_structure_slist_node*
		ptr_node
			= __synapse_structure_slist_node_initialize
					(pList, pData, pDataSize);

	while
		(!__atomic_compare_exchange_n
			(&pList->entry, &pList->entry, 
				ptr_node, false, __ATOMIC_RELEASE, __ATOMIC_RELAXED));
}

__synapse_structure_slist_node*
	__synapse_structure_slist_pop
		(__synapse_structure_slist_head* pList)
{
	__synapse_structure_slist_node*
		ptr_pop
			= NULL;
	do
	{
		ptr_pop
			= pList->entry;
		
		if(!ptr_pop)
			return NULL;
	} while 
		(!__atomic_compare_exchange_n
			(&pList->entry, &pList->entry,
				pList->entry->node_next, 
					false, __ATOMIC_RELEASE, __ATOMIC_RELAXED));

	return ptr_pop;
}

__synapse_structure_slist_node* 
	__synapse_structure_slist_peek
		(__synapse_structure_slist_head* pList)
{
	return
		pList->entry;
}