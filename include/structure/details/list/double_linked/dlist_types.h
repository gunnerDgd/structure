#pragma once
#include <stdint.h>
#include <synapse/memory/interface/memory_manager.h>

typedef struct 
	__synapse_structure_dlist_node
{
	void*  node_ptr ;
	size_t node_size;
	
	void*
		node_head; // Parent Head of the Node.
				   // Used for Identify Node's Head.
	struct __synapse_structure_dlist_node
		*prev,
		*next;
} 
	__synapse_structure_dlist_node;

typedef struct 
	__synapse_structure_dlist_head
{
	synapse_memory_manager
		*mman;

	__synapse_structure_dlist_node
		*entry   ,
		*backmost;
} __synapse_structure_dlist_head;