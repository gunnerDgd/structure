#pragma once
#include <stdint.h>

typedef struct synapse_structure_single_linked		{ void* opaque; } synapse_structure_single_linked	  ;
typedef struct synapse_structure_single_linked_node { void* opaque; } synapse_structure_single_linked_node;
typedef struct synapse_structure_single_linked_mman
{
	void* mman_context;
	void* (*allocate)  (void*, void*, size_t);
	void  (*deallocate)(void*, void*, size_t);
	void* (*resize)	   (void*, void*, size_t);

	size_t(*copy_from)(void*, void*, size_t);
	size_t(*copy_to)  (void*, void*, size_t);
} synapse_structure_single_linked_mman;

synapse_structure_single_linked
synapse_structure_single_linked_initialize(synapse_structure_single_linked_mman);

synapse_structure_single_linked
synapse_structure_single_linked_initialize_default();

void
synapse_structure_single_linked_destroy  (synapse_structure_single_linked);

synapse_structure_single_linked_node 
synapse_structure_single_linked_insert_at(synapse_structure_single_linked, void*, size_t, size_t);

synapse_structure_single_linked_node 
synapse_structure_single_linked_insert_front(synapse_structure_single_linked, void*, size_t);

synapse_structure_single_linked_node 
synapse_structure_single_linked_insert_back (synapse_structure_single_linked, void*, size_t);

void synapse_structure_single_linked_erase_at   (synapse_structure_single_linked, size_t);
void synapse_structure_single_linked_erase_back (synapse_structure_single_linked);
void synapse_structure_single_linked_erase_front(synapse_structure_single_linked);

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_front(synapse_structure_single_linked);

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_back (synapse_structure_single_linked);

synapse_structure_single_linked_node
synapse_structure_single_linked_retrieve_at   (synapse_structure_single_linked, size_t);