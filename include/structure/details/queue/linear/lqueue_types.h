#pragma once
#include <stdint.h>

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
} __synapse_structure_lqueue_head;

