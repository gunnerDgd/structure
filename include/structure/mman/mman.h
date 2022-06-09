#pragma once

typedef struct synapse_structure_mman
{
	void*   mman_context;
	void* (*allocate)  (void*, void*, size_t);
	void  (*deallocate)(void*, void*, size_t);
	void* (*resize)	   (void*, void*, size_t);

	size_t(*copy_from) (void*, void*, size_t);
	size_t(*copy_to)   (void*, void*, size_t);
} synapse_structure_mman;

#define synapse_structure_mman_allocate(pMman, pHint, pSize)\
	pMman.allocate  (pMman.mman_context, pHint, pSize)

#define synapse_structure_mman_deallocate(pMman, pDealloc, pSize)\
	pMman.deallocate(pMman.mman_context, pDealloc, pSize)

#define synapse_structure_mman_resize(pMman, pDealloc, pSize)\
	pMman.resize	(pMman.mman_context, pDealloc, pSize)

#define synapse_structure_mman_copy_from(pMman, pDest, pSrc, pSize)\
	pMman.copy_from(pDest, pSrc, pSize)

#define synapse_structure_mman_copy_to(pMman, pDest, pSrc, pSize)\
	pMman.copy_to(pDest, pSrc, pSize)