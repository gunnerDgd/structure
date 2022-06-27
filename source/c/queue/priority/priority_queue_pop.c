#include <structure/queue/priority/priority_queue_pop.h>
#include <structure/queue/priority/details/pqueue_pop.h>

synapse_structure_priority_queue_node
synapse_structure_priority_queue_pop_front
	(synapse_structure_priority_queue pQueue)
{
	synapse_structure_priority_queue_node ptr_node
		= { .opaque = __synapse_structure_pqueue_pop_front
						(pQueue.opaque) };

	return
		ptr_node;
}

synapse_structure_priority_queue_node
synapse_structure_priority_queue_pop_back
	(synapse_structure_priority_queue pQueue)
{
	synapse_structure_priority_queue_node ptr_node
		= { .opaque = __synapse_structure_pqueue_pop_back
						(pQueue.opaque) };

	return
		ptr_node;
}