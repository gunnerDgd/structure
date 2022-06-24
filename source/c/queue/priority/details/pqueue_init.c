#include <structure/queue/priority/details/pqueue_init.h>
#include <stdlib.h>

__synapse_structure_pqueue_head*
__synapse_structure_pqueue_initialize
	(synapse_memory_mman_traits* pMman)
{
	__synapse_structure_pqueue_head* ptr_pqueue
		= malloc(sizeof(__synapse_structure_pqueue_head));

	ptr_pqueue->ptr_pqueue_mman
		= pMman;

	return ptr_pqueue;
}

void
__synapse_structure_pqueue_cleanup
	(__synapse_structure_pqueue_head* pHead)
{
	
}