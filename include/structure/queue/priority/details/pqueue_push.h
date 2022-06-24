#pragma once
#include <structure/queue/priority/details/pqueue_type.h>

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_front
	(__synapse_structure_pqueue_head*, void*, size_t);

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_front_existing
	(__synapse_structure_pqueue_head*, __synapse_structure_pqueue_node*);

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_back
	(__synapse_structure_pqueue_head*, void*, size_t);

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_push_back_existing
	(__synapse_structure_pqueue_head*, __synapse_structure_pqueue_node*);