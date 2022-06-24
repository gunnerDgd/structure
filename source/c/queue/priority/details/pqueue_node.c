#include <structure/queue/priority/details/pqueue_node.h>
#include <string.h>

__synapse_structure_pqueue_node*
__synapse_structure_pqueue_node_initialize
	(synapse_memory_mman_traits* pMman, __synapse_structure_pqueue_key* pKey, void* pNodePtr, size_t pNodeSize)
{
	__synapse_structure_pqueue_node* ptr_node
		= synapse_memory_mman_traits_allocate(pMman, NULL, sizeof(__synapse_structure_pqueue_node));

	ptr_node->ptr_node_entity
		= synapse_memory_mman_traits_allocate(pMman, NULL, pNodeSize);
	ptr_node->ptr_node_entity_size
		= pNodeSize;
	ptr_node->ptr_node_key
		= pKey;

	memcpy
		(ptr_node->ptr_node_entity, pNodePtr, pNodeSize);
	return ptr_node;
}

void
__synapse_structure_pqueue_node_cleanup
	(synapse_memory_mman_traits* pMman, __synapse_structure_pqueue_node* pNode)
{
	synapse_memory_mman_traits_deallocate
		(pMman, pNode->ptr_node_entity, pNode->ptr_node_entity_size);
	synapse_memory_mman_traits_deallocate
		(pMman, pNode, sizeof(__synapse_structure_pqueue_node));
}