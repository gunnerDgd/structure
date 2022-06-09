#include <structure/details/queue/circular/cqueue_init.h>
#include <Windows.h>

__synapse_structure_cqueue_head*
__synapse_structure_cqueue_initialize(size_t pBlockSize, size_t pNodeCount)
{
	__synapse_structure_cqueue_head* ptr_head =
		malloc(sizeof(__synapse_structure_cqueue_head));

	ptr_head->ptr_entity  = VirtualAlloc(NULL, pBlockSize * pNodeCount, MEM_COMMIT, PAGE_READWRITE);
	ptr_head->entry		  = malloc	   (sizeof(__synapse_structure_cqueue_node) * pNodeCount);
	
	ptr_head->node_size   = pBlockSize;
	ptr_head->entire_size = pBlockSize * pNodeCount;

	__synapse_structure_cqueue_node* ptr_init
		 = ptr_head->entry;

	for(size_t ptr_init = 0				;
			   ptr_init < pNodeCount - 1;
			   ptr_init++)
	{
		ptr_head->entry[ptr_init].ptr_entity = (uint8_t*)ptr_head->ptr_entity + (pBlockSize * ptr_init);
		ptr_head->entry[ptr_init].next		 = &ptr_head->entry[ptr_init + 1];
	}

	ptr_head->entry[pNodeCount - 1].next	   = ptr_head->entry;
	ptr_head->entry[pNodeCount - 1].ptr_entity = (uint8_t*)ptr_head->ptr_entity + (pBlockSize * (pNodeCount - 1));

	ptr_head->wrptr = ptr_head->entry->next;
	ptr_head->rdptr = ptr_head->entry      ;
	
	return ptr_head;
}

void
__synapse_structure_cqueue_cleanup(__synapse_structure_cqueue_head* pHead)
{
	free	   (pHead->entry)				   ;
	VirtualFree(pHead->ptr_entity, 0, MEM_FREE);
}