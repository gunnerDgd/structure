#pragma once
#include <stdint.h>

typedef struct __synapse_structure_cqueue_node
{
	void*  ptr_entity ;
	struct __synapse_structure_cqueue_node*
		next;
} __synapse_structure_cqueue_node;

typedef struct __synapse_structure_cqueue_head
{
	void*
		ptr_entity;
	__synapse_structure_cqueue_node*
		entry;

	__synapse_structure_cqueue_node
		* rdptr,
		* wrptr;

	size_t entire_size,
		   node_size  ;	
} __synapse_structure_cqueue_head;