#pragma once
#include <stdint.h>
#include <structure/mman/mman.h>

typedef struct __synapse_structure_lqueue_node
{
	void*  ptr_entity ;
	size_t size_entity;

	struct __synapse_structure_lqueue_node
		* prev,
		* next;
} __synapse_structure_lqueue_node;

typedef struct __synapse_structure_lqueue_head
{
	__synapse_structure_lqueue_node
		* frontmost,
		* backmost ;

	size_t
		count;
	synapse_structure_mman
		mman;
} __synapse_structure_lqueue_head;

