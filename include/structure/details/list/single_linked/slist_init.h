#pragma once
#include <structure/details/list/single_linked/slist_types.h>

__synapse_structure_slist_head* __synapse_structure_slist_initialize (__synapse_structure_slist_mman*);
void							__synapse_structure_slist_destroy    (__synapse_structure_slist_head*);

long						    __synapse_structure_slist_reference  (__synapse_structure_slist_head*);
long						    __synapse_structure_slist_dereference(__synapse_structure_slist_head*);