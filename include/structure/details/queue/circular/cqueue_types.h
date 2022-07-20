#pragma once
#include <stdint.h>
#include <synapse/memory/memory.h>

typedef struct 
	__synapse_structure_cqueue_node
{
	void*  
		ptr_entity;
	struct __synapse_structure_cqueue_node*
		ptr_next  ;
} __synapse_structure_cqueue_node;

typedef struct 
	__synapse_structure_cqueue_head
{
	void*
		ptr_cqueue_arena;
	__synapse_structure_cqueue_node*
		ptr_cqueue_entry;

	__synapse_structure_cqueue_node
		* ptr_cqueue_rdptr,
		* ptr_cqueue_wrptr;

	size_t 
		count_cqueue,
		size_cqueue_node;	
} __synapse_structure_cqueue_head;