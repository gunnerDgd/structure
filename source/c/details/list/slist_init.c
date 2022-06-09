#include <structure/details/list/single_linked/slist_init.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_structure_slist_head* 
__synapse_structure_slist_initialize(synapse_structure_mman* pMman)
{
	__synapse_structure_slist_head*
		ptr_head = malloc(sizeof(__synapse_structure_slist_head));

	ptr_head->entry			  = NULL;
	ptr_head->back			  = NULL;
	ptr_head->front			  = NULL;
	
	ptr_head->mman.allocate   = pMman->allocate  ;
	ptr_head->mman.deallocate = pMman->deallocate;
	ptr_head->mman.resize     = pMman->resize    ;

	ptr_head->mman.copy_from  = pMman->copy_from ;
	ptr_head->mman.copy_to    = pMman->copy_to   ;

	ptr_head->node_count	  = 0;
	ptr_head->reference_count = 0;

	return ptr_head;
}

void __synapse_structure_slist_destroy(__synapse_structure_slist_head* pHead)
{
	synapse_structure_mman_deallocate(pHead->mman, NULL, 0);
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