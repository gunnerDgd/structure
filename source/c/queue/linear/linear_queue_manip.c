#include <structure/queue/linear/linear_queue_manip.h>
#include <structure/details/queue/linear/lqueue_manip.h>

void
synapse_structure_linear_queue_push_back(synapse_structure_linear_queue pQueue, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_push_back(pQueue.opaque, pData, pDataSize);
}

void
synapse_structure_linear_queue_push_front(synapse_structure_linear_queue pQueue, void* pData, size_t pDataSize)
{
	__synapse_structure_lqueue_push_front(pQueue.opaque, pData, pDataSize);
}

synapse_structure_linear_queue_node
synapse_structure_linear_queue_retrieve_front(synapse_structure_linear_queue pQueue)
{
	synapse_structure_linear_queue_node ptr_node =
		{ .opaque = __synapse_structure_lqueue_retrieve_front(pQueue.opaque) };

	return ptr_node;
}

synapse_structure_linear_queue_node
synapse_structure_linear_queue_retrieve_back(synapse_structure_linear_queue pQueue)
{
	synapse_structure_linear_queue_node ptr_node =
		{ .opaque = __synapse_structure_lqueue_retrieve_back(pQueue.opaque) };

	return ptr_node;
}

void
synapse_structure_lqueue_push_back_node(synapse_structure_linear_queue pQueue, synapse_structure_linear_queue_node pNode)
{
	__synapse_structure_lqueue_push_back_node(pQueue.opaque, pNode.opaque);
}

void
synapse_structure_lqueue_push_front_node(synapse_structure_linear_queue pQueue, synapse_structure_linear_queue_node pNode)
{
	__synapse_structure_lqueue_push_front_node(pQueue.opaque, pNode.opaque);
}

void
synapse_structure_linear_queue_pop_back(synapse_structure_linear_queue pQueue)
{
	__synapse_structure_lqueue_pop_back(pQueue.opaque);
}

void
synapse_structure_linear_queue_pop_front(synapse_structure_linear_queue pQueue)
{
	__synapse_structure_lqueue_pop_front(pQueue.opaque);
}