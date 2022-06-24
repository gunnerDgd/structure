#include <structure/queue/priority/details/pqueue_pop.h>

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_pop_front
	(__synapse_structure_pqueue_head* pQueue)
{
	__synapse_structure_pqueue_node* ptr_front
		= pQueue->ptr_pqueue_frontmost;

	if (pQueue->ptr_pqueue_frontmost)
		pQueue->ptr_pqueue_frontmost = pQueue->ptr_pqueue_frontmost->ptr_node_next;

	return
		ptr_front;
}

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_pop_back
	(__synapse_structure_pqueue_head* pQueue)
{
	__synapse_structure_pqueue_node* ptr_back
		= pQueue->ptr_pqueue_backmost;

	if (pQueue->ptr_pqueue_backmost)
		pQueue->ptr_pqueue_backmost = pQueue->ptr_pqueue_backmost->ptr_node_prev;

	return
		ptr_back;
}