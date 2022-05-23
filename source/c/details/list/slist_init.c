#include <structure/details/list/single_linked/slist_init.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_structure_slist_head* 
__synapse_structure_slist_initialize(__synapse_structure_slist_mman* pMman)
{
	__synapse_structure_slist_head*
		ptr_head = malloc(sizeof(__synapse_structure_slist_head));

	ptr_head->entry			  = NULL;
	ptr_head->mman.allocate   = (pMman->allocate)   ? pMman->allocate   : __synapse_structure_slist_mman_default_allocate  ;
	ptr_head->mman.deallocate = (pMman->deallocate) ? pMman->deallocate : __synapse_structure_slist_mman_default_deallocate;
	ptr_head->mman.resize     = (pMman->resize)	    ? pMman->resize	    : __synapse_structure_slist_mman_default_resize	 ;

	ptr_head->mman.copy_from  = (pMman->copy_from)  ? pMman->copy_from  : __synapse_structure_slist_mman_default_copy_from ;
	ptr_head->mman.copy_to    = (pMman->copy_to)    ? pMman->copy_to    : __synapse_structure_slist_mman_default_copy_to   ;

	return ptr_head;
}

void __synapse_structure_slist_destroy(__synapse_structure_slist_head* pHead)
{
	__synapse_structure_slist_mman_deallocate(pHead->mman, NULL, 0);
}

long __synapse_structure_slist_reference(__synapse_structure_slist_head* pHead)
{
	InterlockedIncrement(&pHead->reference_count);
	return				  pHead->reference_count ;
}

long __synapse_structure_slist_dereference(__synapse_structure_slist_head* pHead)
{
	if(pHead->reference_count > 0)
		InterlockedDecrement(&pHead->reference_count);
	return					  pHead->reference_count;
}