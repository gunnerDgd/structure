#include <structure/details/list/single_linked/slist_mman.h>
#include <Windows.h>

__synapse_structure_slist_mman
__synapse_structure_slist_mman_initialize(void* pMmanContext, void* (*pMmanAllocate)  (void*, void*, size_t),
															  void  (*pMmanDeallocate)(void*, void*, size_t),
															  void* (*pMmanResize)    (void*, void*, size_t),
															  size_t(*pMmanCopyFrom)  (void*, void*, size_t),
															  size_t(*pMmanCopyTo)    (void*, void*, size_t))
{
	__synapse_structure_slist_mman mman = 
	{
		.allocate   = (pMmanAllocate)   ? pMmanAllocate   : &__synapse_structure_slist_mman_default_allocate  ,
		.deallocate = (pMmanDeallocate) ? pMmanDeallocate : &__synapse_structure_slist_mman_default_deallocate,
		.resize     = (pMmanResize)	    ? pMmanResize	  : &__synapse_structure_slist_mman_default_resize    ,
		.copy_from  = (pMmanCopyFrom)   ? pMmanCopyFrom   : &__synapse_structure_slist_mman_default_copy_from ,
		.copy_to    = (pMmanCopyTo)		? pMmanCopyTo     : &__synapse_structure_slist_mman_default_copy_to
	};

	return mman;
}

void
__synapse_structure_slist_mman_destroy(__synapse_structure_slist_mman* pMman)
{
	pMman->deallocate(pMman->mman_context, NULL, 0);
}

void* __synapse_structure_slist_mman_default_allocate  (void* pMman, void* pHint   , size_t pSize) { return malloc (pSize); }
void  __synapse_structure_slist_mman_default_deallocate(void* pMman, void* pDealloc, size_t pSize) {		free   (pSize); }
void* __synapse_structure_slist_mman_default_resize    (void* pMman, void* pHint   , size_t pSize) { return realloc(pHint, pSize); }

size_t __synapse_structure_slist_mman_default_copy_from(void* pDest, void* pSrc, size_t pSize)	   { memcpy(pDest, pSrc, pSize); return pSize; }
size_t __synapse_structure_slist_mman_default_copy_to  (void* pDest, void* pSrc, size_t pSize)	   { memcpy(pDest, pSrc, pSize); return pSize; }