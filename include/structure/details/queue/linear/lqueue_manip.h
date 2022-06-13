#pragma once
#include <structure/details/queue/linear/lqueue_types.h>

void
__synapse_structure_lqueue_push_back	 (__synapse_structure_lqueue_head*, void*, size_t);

void
__synapse_structure_lqueue_push_front	 (__synapse_structure_lqueue_head*, void*, size_t);

void
__synapse_structure_lqueue_push_back_node (__synapse_structure_lqueue_head*, __synapse_structure_lqueue_node*);

void
__synapse_structure_lqueue_push_front_node(__synapse_structure_lqueue_head*, __synapse_structure_lqueue_node*);

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_front(__synapse_structure_lqueue_head*);

__synapse_structure_lqueue_node*
__synapse_structure_lqueue_retrieve_back (__synapse_structure_lqueue_head*);

void
__synapse_structure_lqueue_pop_back		 (__synapse_structure_lqueue_head*);

void
__synapse_structure_lqueue_pop_front     (__synapse_structure_lqueue_head*);