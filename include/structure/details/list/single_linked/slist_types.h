#pragma once
#include <synapse/memory/interface/memory_manager.h>

#include <stdint.h>
#include <stdlib.h>

typedef struct 
	__synapse_structure_slist_node
{
	void*  
		data_ptr ;
	size_t 
		data_size;

	void
		*node_parent;
	volatile struct __synapse_structure_slist_node
		*node_next;
} __synapse_structure_slist_node;

typedef struct 
	__synapse_structure_slist_head
{
	volatile __synapse_structure_slist_node
		* entry;
	synapse_memory_manager
		* mman ;
} __synapse_structure_slist_head;