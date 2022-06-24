#include <structure/queue/priority/details/pqueue_push.h>

#include <structure/queue/priority/details/pqueue_node.h>
#include <structure/queue/priority/details/pqueue_node_key.h>

#include <stdlib.h>
#include <string.h>

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_front
	(__synapse_structure_pqueue_head* pQueue, void* pQueuePtr, size_t pQueueSize)
{	
	return
		__synapse_structure_pqueue_node_initialize
			(pQueue->ptr_pqueue_mman, 
			 __synapse_structure_pqueue_key_initialize_from_existing
				(pQueue->ptr_pqueue_mman, pQueue->ptr_pqueue_frontmost->ptr_node_key),
			 pQueuePtr, pQueueSize);
}

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_front_existing
	(__synapse_structure_pqueue_head* pQueue, __synapse_structure_pqueue_node* pQueueNode)
{
	memcpy
		(pQueueNode->ptr_node_key->ptr_pqueue_key, 
		 pQueue->ptr_pqueue_frontmost->ptr_node_key->ptr_pqueue_key,
		 pQueue->ptr_pqueue_frontmost->ptr_node_key->sz_pqueue_key);

	pQueueNode->ptr_node_next
		= pQueue->ptr_pqueue_frontmost;
	pQueueNode->ptr_node_prev
		= NULL;
	
	pQueue->ptr_pqueue_frontmost->ptr_node_prev
		= pQueueNode;
	pQueue->ptr_pqueue_frontmost
		= pQueueNode;

	return
		pQueueNode;
}

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_back
	(__synapse_structure_pqueue_head* pQueue, void* pQueuePtr, size_t pQueueSize)
{
	return
		__synapse_structure_pqueue_node_initialize
			(pQueue->ptr_pqueue_mman, 
			 __synapse_structure_pqueue_key_initialize_from_existing
				(pQueue->ptr_pqueue_mman, pQueue->ptr_pqueue_backmost->ptr_node_key),
			 pQueuePtr, pQueueSize);
}

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_back_existing
	(__synapse_structure_pqueue_head* pQueue, __synapse_structure_pqueue_node* pQueueNode)
{
	memcpy
		(pQueueNode->ptr_node_key->ptr_pqueue_key, 
		 pQueue->ptr_pqueue_backmost->ptr_node_key->ptr_pqueue_key,
		 pQueue->ptr_pqueue_backmost->ptr_node_key->sz_pqueue_key);

	pQueueNode->ptr_node_prev
		= pQueue->ptr_pqueue_backmost;
	pQueueNode->ptr_node_next
		= NULL;
	
	pQueue->ptr_pqueue_backmost->ptr_node_next
		= pQueueNode;
	pQueue->ptr_pqueue_backmost
		= pQueueNode;

	return
		pQueueNode;
}