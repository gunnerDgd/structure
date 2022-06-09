#pragma once
#include <structure/list/double_linked_type.h>
#include <structure/mman/mman_default.h>

synapse_structure_double_linked
synapse_structure_double_linked_initialize		  (synapse_structure_mman);

synapse_structure_double_linked
synapse_structure_double_linked_initialize_default();

void
synapse_structure_double_linked_cleanup			  (synapse_structure_double_linked);