#pragma once
#include <structure/defines/handle/opaque_handle.h>

#include <stdint.h>
#include <stddef.h>

typedef struct
	synapse_structure_circular_queue_node
{
	void*
		ptr_node_data;
	size_t
		size_node_data;
} synapse_structure_circular_queue_node;

synapse_structure_opaque_handle_declare
	(synapse_structure_circular_queue);