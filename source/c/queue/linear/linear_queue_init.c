#include <structure/queue/linear/linear_queue_init.h>
#include <structure/details/queue/linear/lqueue_init.h>

synapse_structure_linear_queue
synapse_structure_linear_queue_initialize()
{
	synapse_structure_linear_queue ptr_lqueue =
		{ .opaque = __synapse_structure_lqueue_initialize() };

	return ptr_lqueue;
}

void
synapse_structure_linear_queue_cleanup(synapse_structure_linear_queue pQueue)
{
	__synapse_structure_lqueue_cleanup(pQueue.opaque);
}