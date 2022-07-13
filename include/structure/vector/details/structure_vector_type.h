#pragma once
#include <stdint.h>
#include <memory/mman/mman_traits.h>

typedef struct
	__synapse_structure_vector_node
{
	void*
		vec_data_ptr;
	size_t
		vec_data_size;
} __synapse_structure_vector_node;

typedef struct
	__synapse_structure_vector
{
	__synapse_structure_vector_node*
		vec_node_ptr;
	synapse_memory_mman_block
		vec_mman_mblock;
	synapse_memory_mman_traits*
		vec_mman;

	size_t
		vec_node_size ,
		vec_node_count,
		vec_node_count_occupied;
} __synapse_structure_vector;