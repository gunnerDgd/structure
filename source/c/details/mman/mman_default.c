#include <structure/details/mman/default/mman_default.h>

#include <stdlib.h>
#include <string.h>

void* __synapse_structure_mman_allocate  (void* pMman, void* pHint   , size_t pSize) { return malloc (pSize)	   ; }
void  __synapse_structure_mman_deallocate(void* pMman, void* pDealloc, size_t pSize) {		  free   (pDealloc)	   ; }
void* __synapse_structure_mman_resize    (void* pMman, void* pHint   , size_t pSize) { return realloc(pHint, pSize); }

size_t __synapse_structure_mman_copy_from(void* pDest, void* pSrc, size_t pSize)	 { memcpy(pDest, pSrc, pSize); return pSize; }
size_t __synapse_structure_mman_copy_to  (void* pDest, void* pSrc, size_t pSize)	 { memcpy(pDest, pSrc, pSize); return pSize; }