#pragma once
#include <stdint.h>

typedef struct __synapse_structure_slist_mman
{
	void*  mman_context					    ;
	void*(*allocate)  (void*, void*, size_t);
	void (*deallocate)(void*, void*, size_t);
	void*(*resize)	  (void*, void*, size_t);

	size_t(*copy_from)(void*, void*, size_t);
	size_t(*copy_to)  (void*, void*, size_t);
} __synapse_structure_slist_mman;

#define __synapse_structure_slist_mman_allocate(pMman, pHint, pSize)\
	pMman.allocate  (pMman.mman_context, pHint, pSize)

#define __synapse_structure_slist_mman_deallocate(pMman, pDealloc, pSize)\
	pMman.deallocate(pMman.mman_context, pDealloc, pSize)

#define __synapse_structure_slist_mman_resize(pMman, pDealloc, pSize)\
	pMman.resize	(pMman.mman_context, pDealloc, pSize)

#define __synapse_structure_slist_mman_copy_from(pMman, pDest, pSrc, pSize)\
	pMman.copy_from(pDest, pSrc, pSize)

#define __synapse_structure_slist_mman_copy_to(pMman, pDest, pSrc, pSize)\
	pMman.copy_to(pDest, pSrc, pSize)

__synapse_structure_slist_mman
__synapse_structure_slist_mman_initialize(void*, void* (*)(void*, void*, size_t),
												 void  (*)(void*, void*, size_t),
												 void* (*)(void*, void*, size_t),
												 size_t(*)(void*, void*, size_t),
												 size_t(*)(void*, void*, size_t));

void
__synapse_structure_slist_mman_destroy	 (__synapse_structure_slist_mman*);

void*  __synapse_structure_slist_mman_default_allocate  (void*, void*, size_t);
void   __synapse_structure_slist_mman_default_deallocate(void*, void*, size_t);
void*  __synapse_structure_slist_mman_default_resize    (void*, void*, size_t);

size_t __synapse_structure_slist_mman_default_copy_from (void*, void*, size_t);
size_t __synapse_structure_slist_mman_default_copy_to   (void*, void*, size_t);