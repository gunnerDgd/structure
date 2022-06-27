#include <structure/queue/priority/priority_queue_push.h>
#include <structure/queue/priority/details/pqueue_push.h>

synapse_structure_priority_queue_node
synapse_structure_priority_queue_push_front
	(synapse_structure_priority_queue pQueue, void* pQueuePtr, size_t pQueueSize)
{
	synapse_structure_priority_queue_node ptr_node
		= { .opaque = __synapse_structure_pqueue_push_front
						(pQueue.opaque, pQueuePtr, pQueueSize) };

	return ptr_node;
}

synapse_structure_priority_queue_node
synapse_structure_priority_queue_push_front_existing
	(synapse_structure_priority_queue pQueue, synapse_structure_priority_queue_node pQueueNode)
{
	__synapse_structure_pqueue_push_back_existing
		(pQueue.opaque, pQueueNode.opaque);
}

synapse_structure_priority_queue_node
synapse_structure_priority_queue_push_back
	(synapse_structure_priority_queue pQueue, void* pQueuePtr, size_t pQueueSize)
{
	synapse_structure_priority_queue_node ptr_node
		= { .opaque = __synapse_structure_pqueue_push_back
							(pQueue.opaque, pQueuePtr, pQueueSize)};

	return ptr_node;
}

synapse_structure_priority_queue_node
synapse_structure_priority_queue_push_back_existing
	(synapse_structure_priority_queue pQueue, synapse_structure_priority_queue_node pQueueNode)
{
	__synapse_structure_pqueue_push_back_existing
		(pQueue.opaque, pQueueNode.opaque);
}