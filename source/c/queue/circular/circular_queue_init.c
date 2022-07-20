#include <structure/queue/circular/circular_queue_init.h>
#include <structure/details/queue/circular/cqueue_init.h>

synapse_structure_circular_queue
	synapse_structure_circular_queue_initialize
		(size_t pBlockSize, size_t pNodeCount)
{
	synapse_structure_opaque_handle_init
		(synapse_structure_circular_queue, hnd_cqueue,
			__synapse_structure_cqueue_initialize
				(pBlockSize, pNodeCount));

	return hnd_cqueue;
}

void
synapse_structure_circular_queue_cleanup
	(synapse_structure_circular_queue pCqueue)
{
	__synapse_structure_cqueue_cleanup
		(synapse_structure_opaque_handle_reference
			(pCqueue));
}