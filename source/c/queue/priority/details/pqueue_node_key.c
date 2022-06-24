#include <structure/queue/priority/details/pqueue_node_key.h>
#include <string.h>

__synapse_structure_pqueue_key*
__synapse_structure_pqueue_key_initialize
	(synapse_memory_mman_traits* pMman, void* pKeyPtr, size_t pKeySize,
	 int(*pKeyCmp)(void*, void*))
{
	__synapse_structure_pqueue_key* ptr_key
		= synapse_memory_mman_traits_allocate(pMman, NULL, sizeof(__synapse_structure_pqueue_key));

	ptr_key->ptr_pqueue_key_compare
		= pKeyCmp;
	ptr_key->ptr_pqueue_key
		= pKeyPtr;
	ptr_key->sz_pqueue_key
		= pKeySize;

	return ptr_key;
}

__synapse_structure_pqueue_key*
__synapse_structure_pqueue_key_initialize_from_existing
	(synapse_memory_mman_traits* pMman, __synapse_structure_pqueue_key* pKey)
{
	__synapse_structure_pqueue_key* ptr_key
		= synapse_memory_mman_traits_allocate(pMman, NULL, sizeof(__synapse_structure_pqueue_key));
	ptr_key->ptr_pqueue_key
		= synapse_memory_mman_traits_allocate(pMman, NULL, pKey->sz_pqueue_key);

	ptr_key->ptr_pqueue_key_compare
		= pKey->ptr_pqueue_key_compare;
	memcpy
		(ptr_key->ptr_pqueue_key, pKey->ptr_pqueue_key, pKey->sz_pqueue_key);
	return
		ptr_key;
}

void
__synapse_structure_pqueue_key_cleanup
	(synapse_memory_mman_traits*, __synapse_structure_pqueue_key*);