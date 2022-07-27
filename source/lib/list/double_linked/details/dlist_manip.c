#include <structure/details/list/double_linked/dlist_manip.h>
#include <structure/details/list/double_linked/dlist_init.h>

#include <Windows.h>

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_front
	(__synapse_structure_dlist_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_node* 
		ptr_node
			= __synapse_structure_dlist_node_initialize
					(pHead, pData, pDataSize);

	ptr_node->next		= pHead->entry;
	ptr_node->prev	    = NULL		  ;
	ptr_node->node_head = pHead		  ;

						  pHead->entry    = ptr_node;
	if (!pHead->backmost) pHead->backmost = ptr_node;
	return									ptr_node;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_back
	(__synapse_structure_dlist_head* pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_node
		*ptr_node
			= __synapse_structure_dlist_node_initialize
					(pHead, pData, pDataSize);

	ptr_node->next		= NULL;
	ptr_node->prev		= pHead->backmost;
	ptr_node->node_head = pHead;

	if(pHead->backmost) pHead->backmost->next = ptr_node;
					    pHead->backmost		  = ptr_node;
	if (!pHead->entry)  pHead->entry		  = ptr_node;
	return									    ptr_node;
}

__synapse_structure_dlist_node*
__synapse_structure_dlist_insert_at
	(__synapse_structure_dlist_head* pHead, __synapse_structure_dlist_node* pNode, void* pData, size_t pDataSize)
{
	__synapse_structure_dlist_node
		*ptr_seek
			= pNode,
		* ptr_node
			= __synapse_structure_dlist_node_initialize
				(pHead, pData, pDataSize);
	
	ptr_node->next		= ptr_seek->next;
	ptr_node->prev		= ptr_seek;
	ptr_node->node_head = pHead;

						ptr_seek->next		 = ptr_node;
	if (ptr_seek->next) ptr_seek->next->prev = ptr_node;

	return									   ptr_node;
}

void
__synapse_structure_dlist_erase_front
	(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node
		*ptr_erase
			= pHead->entry;

	if (!ptr_erase) return;

	pHead->entry
		= ptr_erase->next;
	if(!pHead->entry)
		pHead->backmost = NULL;
	__synapse_structure_dlist_node_cleanup
		(pHead, ptr_erase);
}

void
__synapse_structure_dlist_erase_back
	(__synapse_structure_dlist_head* pHead)
{
	__synapse_structure_dlist_node* ptr_erase
		= pHead->backmost;

	if (!ptr_erase) return;

	pHead->backmost 
		= ptr_erase->prev;
	if(!pHead->backmost)
		pHead->backmost = pHead->entry;
	
	__synapse_structure_dlist_node_cleanup
		(pHead, ptr_erase);
}


void
__synapse_structure_dlist_erase_at
	(__synapse_structure_dlist_head* pHead, __synapse_structure_dlist_node* pNode)
{
	if (pNode->node_head != pHead)
		return;

	if(!pNode->prev)
		__synapse_structure_dlist_erase_front
			(pHead);
	else if(!pNode->next)
		__synapse_structure_dlist_erase_back
			(pHead);
	else 
	{
		pNode->prev->next = pNode->next;
		pNode->next->prev = pNode->prev;

		__synapse_structure_dlist_node_cleanup
			(pHead, pNode); 
	}
}