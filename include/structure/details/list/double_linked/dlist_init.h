#pragma once
#include <structure/details/list/double_linked/dlist_types.h>

__synapse_structure_dlist_head*
__synapse_structure_dlist_initialize		(synapse_memory_mman_traits*);

void
__synapse_structure_dlist_cleanup			(__synapse_structure_dlist_head*);