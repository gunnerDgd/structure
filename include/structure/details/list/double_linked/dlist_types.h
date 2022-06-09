#pragma once
#include <stdint.h>
#include <structure/mman/mman.h>

typedef struct __synapse_structure_dlist_node
{
	void*  node_ptr ;
	size_t node_size;

	struct __synapse_structure_dlist_node* prev,
										 * next;
} __synapse_structure_dlist_node;

typedef struct __synapse_structure_dlist_head
{
	synapse_structure_mman		    mman    ;
	__synapse_structure_dlist_node* entry   ,
								  * backmost;

	volatile unsigned int			reference_count;
	volatile unsigned int			node_count	   ;
} __synapse_structure_dlist_head;