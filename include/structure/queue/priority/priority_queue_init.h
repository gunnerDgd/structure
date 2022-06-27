#pragma once
#include <structure/queue/priority/priority_queue_type.h>
#include <memory/mman/mman_traits.h>

synapse_structure_priority_queue
synapse_structure_priority_queue_initialize
	(synapse_memory_mman_traits*);

void
synapse_structure_priority_queue_cleanup
	(synapse_structure_priority_queue);