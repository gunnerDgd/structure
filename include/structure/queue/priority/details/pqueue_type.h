#pragma once
#include <memory/mman/mman_traits.h>

typedef struct __synapse_structure_pqueue_key
{
	void*
		ptr_pqueue_key;
	size_t
		sz_pqueue_key;
	int
		(*ptr_pqueue_key_compare)
			(void*, void*);

} __synapse_structure_pqueue_key;

typedef struct __synapse_structure_pqueue_node
{
	__synapse_structure_pqueue_key*
		ptr_node_key;
	void*
		ptr_node_entity;
	size_t
		ptr_node_entity_size;

	struct __synapse_structure_pqueue_node
		*ptr_node_next,
		*ptr_node_prev;
} __synapse_structure_pqueue_node;

typedef struct __synapse_structure_pqueue_head
{
	synapse_memory_mman_traits*
		ptr_pqueue_mman;
	
	__synapse_structure_pqueue_node
		*ptr_pqueue_frontmost,
		*ptr_pqueue_backmost ;
} __synapse_structure_pqueue_head;