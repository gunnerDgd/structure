#pragma once
#include <structure/details/list/single_linked/slist_types.h>

__synapse_structure_slist_node* __synapse_structure_slist_insert_back (__synapse_structure_slist_head*, void*, size_t);
__synapse_structure_slist_node* __synapse_structure_slist_insert_front(__synapse_structure_slist_head*, void*, size_t);
__synapse_structure_slist_node* __synapse_structure_slist_insert_at   (__synapse_structure_slist_head*, void*, size_t, size_t);

void							__synapse_structure_slist_erase_back  (__synapse_structure_slist_head*);
void							__synapse_structure_slist_erase_front (__synapse_structure_slist_head*);
void							__synapse_structure_slist_erase_at    (__synapse_structure_slist_head*, size_t);

#define __synapse_structure_slist_retrive_front(pHead) pHead->front
#define __synapse_structure_slist_retrive_back(pHead) pHead->back

__synapse_structure_slist_node* 
__synapse_structure_slist_retrive_at(__synapse_structure_slist_head*, size_t);