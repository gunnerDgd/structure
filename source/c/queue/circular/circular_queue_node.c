#include <structure/queue/circular/circular_queue_node.h>
#include <structure/details/queue/circular/cqueue_types.h>

void*
synapse_structure_circular_queue_node_data(synapse_structure_circular_queue_node pNode)
{
	return ((__synapse_structure_cqueue_node*)pNode.opaque)->ptr_entity;
}

size_t
synapse_structure_circular_queue_node_size(synapse_structure_circular_queue pQueue)
{
	return ((__synapse_structure_cqueue_head*)pQueue.opaque)->node_size;
}