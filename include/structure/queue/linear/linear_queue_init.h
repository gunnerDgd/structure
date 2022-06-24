#pragma once
#include <structure/queue/linear/linear_queue_type.h>
#include <memory/mman/mman_traits.h>

synapse_structure_linear_queue
synapse_structure_linear_queue_initialize
	(synapse_memory_mman_traits*);

void
synapse_structure_linear_queue_cleanup
	(synapse_structure_linear_queue);