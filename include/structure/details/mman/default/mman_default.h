#pragma once
#include <stdint.h>

void*  __synapse_structure_mman_allocate  (void*, void*, size_t);
void   __synapse_structure_mman_deallocate(void*, void*, size_t);
void*  __synapse_structure_mman_resize    (void*, void*, size_t);

size_t __synapse_structure_mman_copy_from (void*, void*, size_t);
size_t __synapse_structure_mman_copy_to   (void*, void*, size_t);