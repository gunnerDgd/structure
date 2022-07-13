#pragma once
#include <memory/mman/mman_traits.h>

typedef struct 
	__synapse_structure_slist_node
{
	void*  
		data_ptr ;
	size_t 
		data_size;

	void
		*node_parent;
	synapse_memory_mman_block
		 node_mblock,
		 node_data_mblock;
	struct __synapse_structure_slist_node
		*node_next;
} __synapse_structure_slist_node;

typedef struct 
	__synapse_structure_slist_head
{
	volatile long
		slist_refcount;
	volatile long
		slist_node_count;

	__synapse_structure_slist_node
		* front,
		* back ;
	synapse_memory_mman_traits
		* mman ;
	synapse_memory_mman_block
		  mman_mblock;
} __synapse_structure_slist_head;