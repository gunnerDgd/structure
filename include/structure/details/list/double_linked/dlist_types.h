#pragma once
#include <stdint.h>

#include <synapse/memory/interface/memory_manager.h>
#include <memory/defines/alloc.h>

typedef struct 
	__synapse_structure_dlist_node
{
	void*  
		node_ptr ;
	size_t 
		node_size;
	
	void*
		node_head; // Parent Head of the Node.
				   // Used for Identify Node's Head.
	synapse_memory_block
		mblock_node_ptr,
		mblock_data_ptr;

	struct __synapse_structure_dlist_node
		*prev,
		*next;
} 
	__synapse_structure_dlist_node;

typedef struct __synapse_structure_dlist_head
{
	synapse_memory_manager    
		*mman      ;
	synapse_memory_block
		 hnd_mblock;

	__synapse_structure_dlist_node
		*entry   ,
		*backmost;

	volatile unsigned int
		reference_count;
	volatile unsigned int
		node_count	   ;
} __synapse_structure_dlist_head;