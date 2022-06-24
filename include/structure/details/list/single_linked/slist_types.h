#pragma once
#include <memory/mman/mman_traits.h>

typedef struct __synapse_structure_slist_node
{
	void*  data_ptr ;
	size_t data_size;

	void*  parent_head;
	struct __synapse_structure_slist_node* next;
} __synapse_structure_slist_node;

typedef struct __synapse_structure_slist_head
{
	volatile long					reference_count;
	volatile long					node_count	   ;

	__synapse_structure_slist_node* entry,
								  * front,
								  * back ;
	synapse_memory_mman_traits    * mman ;
} __synapse_structure_slist_head;