#include <stdbool.h>
#include <Windows.h>

#include <structure/details/list/single_linked/slist_init.h>
#include <structure/details/list/single_linked/slist_manip.h>
#include <structure/details/list/single_linked/slist_atomic.h>

void
	__synapse_structure_slist_push
		(__synapse_structure_slist_head* pList, void* pData, size_t pDataSize)
{
	__synapse_structure_slist_node*
		ptr_node
			= __synapse_structure_slist_node_initialize
					(pList, pData, pDataSize);
	do
	{
		ptr_node->node_next
			= pList->entry;
	}
	while 
		(__synapse_structure_slist_cmpxchg
			(&pList->entry, ptr_node->node_next, ptr_node));
}

void
	__synapse_structure_slist_push_node
		(__synapse_structure_slist_head* pList, __synapse_structure_slist_node* pNode)
{
	do
	{
		pNode->node_next
			= pList->entry;
	}
	while 
		(__synapse_structure_slist_cmpxchg
			(&pList->entry, pNode->node_next, pNode));
}

__synapse_structure_slist_node*
	__synapse_structure_slist_pop
		(__synapse_structure_slist_head* pList)
{
	__synapse_structure_slist_node*
		ptr_pop = NULL;

	do
	{
		ptr_pop
			= pList->entry;
		
		if(!ptr_pop) return 0;
	} while 
		(__synapse_structure_slist_cmpxchg
			(&pList->entry, ptr_pop, ptr_pop->node_next));

	return
		ptr_pop;
}

__synapse_structure_slist_node* 
	__synapse_structure_slist_peek
		(__synapse_structure_slist_head* pList)
{
	return
		pList->entry;
}