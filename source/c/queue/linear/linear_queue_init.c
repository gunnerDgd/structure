#include <structure/queue/linear/linear_queue_init.h>
#include <structure/details/queue/linear/lqueue_init.h>

#include <structure/mman/mman_default.h>

synapse_structure_linear_queue
synapse_structure_linear_queue_initialize(synapse_structure_mman pMman)
{
	synapse_structure_linear_queue ptr_lqueue =
		{ .opaque = __synapse_structure_lqueue_initialize(pMman) };

	return ptr_lqueue;
}

synapse_structure_linear_queue
synapse_structure_linear_queue_initialize_default()
{
	return synapse_structure_linear_queue_initialize(synapse_structure_mman_default_initialize());
}

void
synapse_structure_linear_queue_cleanup(synapse_structure_linear_queue pQueue)
{
	__synapse_structure_lqueue_cleanup(pQueue.opaque);
}