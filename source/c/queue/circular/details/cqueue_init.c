#include <structure/details/queue/circular/cqueue_init.h>
#include <Windows.h>

__synapse_structure_cqueue_head*
	__synapse_structure_cqueue_initialize
		(size_t pNodeSize ,
		 size_t pNodeCount)
{
	__synapse_structure_cqueue_head* 
		ptr_head 
			= synapse_system_allocate
					(sizeof(__synapse_structure_cqueue_head));

	ptr_head->ptr_cqueue_arena
		= synapse_system_allocate
				(pNodeSize * pNodeCount);
	ptr_head->ptr_cqueue_entry
		= synapse_system_allocate
				(sizeof(__synapse_structure_cqueue_node) * pNodeCount);
	
	ptr_head->size_cqueue_node  
		= pNodeSize;
	ptr_head->count_cqueue 
		= pNodeCount;

	__synapse_structure_cqueue_node* 
		ptr_init
		 	= ptr_head->ptr_cqueue_entry;

	for(size_t ptr_init = 0				;
			   ptr_init < pNodeCount - 1;
			   ptr_init++)
	{
		ptr_head->ptr_cqueue_entry[ptr_init].ptr_entity 
			= (uint8_t*)ptr_head->ptr_cqueue_arena 
					+ (pNodeSize * ptr_init);

		ptr_head->ptr_cqueue_entry[ptr_init].ptr_next	 
			= &ptr_head->ptr_cqueue_entry[ptr_init + 1];
	}

	ptr_head->ptr_cqueue_entry[pNodeCount - 1].ptr_next
		= ptr_head->ptr_cqueue_entry;
	ptr_head->ptr_cqueue_entry[pNodeCount - 1].ptr_entity
		= (uint8_t*)ptr_head->ptr_cqueue_arena 
				+ (pNodeSize * (pNodeCount - 1));

	ptr_head->ptr_cqueue_rdptr 
		= ptr_head->ptr_cqueue_entry->ptr_next;
	ptr_head->ptr_cqueue_wrptr 
		= ptr_head->ptr_cqueue_entry;
	
	return ptr_head;
}

void
__synapse_structure_cqueue_cleanup(__synapse_structure_cqueue_head* pHead)
{
	synapse_system_deallocate
		(pHead->ptr_cqueue_entry);
	synapse_system_deallocate
		(pHead->ptr_cqueue_arena);
	synapse_system_deallocate
		(pHead);
}