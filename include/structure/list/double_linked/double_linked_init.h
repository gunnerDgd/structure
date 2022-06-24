#pragma once
#include <structure/list/double_linked/double_linked_type.h>
#include <memory/mman/mman_traits.h>

synapse_structure_double_linked
synapse_structure_double_linked_initialize(synapse_memory_mman_traits*);

void
synapse_structure_double_linked_cleanup   (synapse_structure_double_linked);