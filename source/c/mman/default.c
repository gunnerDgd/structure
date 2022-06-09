#include <structure/mman/mman_default.h>
#include <structure/details/mman/default/mman_default.h>

synapse_structure_mman synapse_structure_mman_default_initialize()
{
	synapse_structure_mman mman_default = 
	{
		.allocate   = __synapse_structure_mman_allocate  ,
		.deallocate = __synapse_structure_mman_deallocate,
		.resize		= __synapse_structure_mman_resize	 ,

		.copy_from  = __synapse_structure_mman_copy_from ,
		.copy_to    = __synapse_structure_mman_copy_to   
	}; return mman_default;
}

void synapse_structure_mman_default_destroy(synapse_structure_mman pMman) {}