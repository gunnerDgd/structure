#include <structure/queue/priority/priority_queue_init.h>
#include <structure/queue/priority/details/pqueue_init.h>

synapse_structure_priority_queue
synapse_structure_priority_queue_initialize
	(synapse_memory_mman_traits* pMman)
{
	synapse_structure_priority_queue ptr_pqueue =
		{ .opaque = __synapse_structure_pqueue_initialize(pMman) };

	return ptr_pqueue;
}

void
synapse_structure_priority_queue_cleanup
	(synapse_structure_priority_queue pQueue)
{
	__synapse_structure_pqueue_cleanup
		(pQueue.opaque);
}