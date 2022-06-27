#pragma once
#include <structure/queue/linear/linear_queue_type.h>

void
synapse_structure_linear_queue_push_back 
	(synapse_structure_linear_queue, void*, size_t);

void
synapse_structure_linear_queue_push_front
	(synapse_structure_linear_queue, void*, size_t);

void
synapse_structure_lqueue_push_back_node 
	(synapse_structure_linear_queue, synapse_structure_linear_queue_node);

void
synapse_structure_lqueue_push_front_node
	(synapse_structure_linear_queue, synapse_structure_linear_queue_node);

synapse_structure_linear_queue_node
synapse_structure_linear_queue_retrieve_front
	(synapse_structure_linear_queue);

synapse_structure_linear_queue_node
synapse_structure_linear_queue_retrieve_back 
	(synapse_structure_linear_queue);

void
synapse_structure_linear_queue_pop_back 
	(synapse_structure_linear_queue);

void
synapse_structure_linear_queue_pop_front
	(synapse_structure_linear_queue);