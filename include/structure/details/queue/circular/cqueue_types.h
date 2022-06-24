#pragma once
#include <stdint.h>
#include <memory/mman/mman_traits.h>

typedef struct __synapse_structure_cqueue_node
{
	void*  ptr_entity ;
	struct __synapse_structure_cqueue_node*
		next;
} __synapse_structure_cqueue_node;

typedef struct __synapse_structure_cqueue_head
{
	synapse_memory_mman_traits*
		ptr_mman;
	void*
		ptr_entity;
	__synapse_structure_cqueue_node*
		entry;

	__synapse_structure_cqueue_node
		* rdptr,
		* wrptr;

	size_t node_count,
		   node_size ;	
} __synapse_structure_cqueue_head;