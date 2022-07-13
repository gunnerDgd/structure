#include <structure/vector/details/structure_vector_init.h>
#include <string.h>

__synapse_structure_vector*
	__synapse_structure_vector_initialize
		(synapse_memory_mman_traits* pMman)
{
	synapse_memory_mman_block
		hnd_mblock
			= pMman->allocate
					(pMman->hnd_mman, NULL, sizeof(__synapse_structure_vector));

	__synapse_structure_vector*
		ptr_vector
			= pMman->block_pointer
					(hnd_mblock);

	memset
		(ptr_vector, 0x00, sizeof(__synapse_structure_vector));
	

	return
		ptr_vector;
}

void
	__synapse_structure_vector_cleanup
		(__synapse_structure_vector*);