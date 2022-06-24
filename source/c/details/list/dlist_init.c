#include <structure/details/list/double_linked/dlist_init.h>
#include <structure/mman/mman_default.h>

__synapse_structure_dlist_head*
__synapse_structure_dlist_initialize(synapse_memory_mman_traits* pMman)
{
	__synapse_structure_dlist_head* ptr_head
		= synapse_memory_mman_traits_allocate(pMman, NULL, sizeof(__synapse_structure_dlist_head));
	

	ptr_head->mman     = pMman;
	ptr_head->backmost = NULL  ;
	ptr_head->entry	   = NULL  ;

	ptr_head->node_count      = 0;
	ptr_head->reference_count = 1;

	return ptr_head;
}

void
__synapse_structure_dlist_cleanup(__synapse_structure_dlist_head* pHead)
{

}