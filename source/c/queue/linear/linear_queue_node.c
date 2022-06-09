#include <structure/queue/linear/linear_queue_node.h>
#include <structure/details/queue/linear/lqueue_types.h>

void*
synapse_structure_linear_queue_node_data(synapse_structure_linear_queue_node pNode) 
{
	return ((__synapse_structure_lqueue_node*)pNode.opaque)->ptr_entity;
}

size_t
synapse_structure_linear_queue_node_size(synapse_structure_linear_queue_node pNode)
{
	return ((__synapse_structure_lqueue_node*)pNode.opaque)->size_entity;
}