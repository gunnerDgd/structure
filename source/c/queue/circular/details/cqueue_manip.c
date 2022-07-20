#include <structure/details/queue/circular/cqueue_manip.h>
#include <string.h>

__synapse_structure_cqueue_node*
	__synapse_structure_cqueue_read_from
		(__synapse_structure_cqueue_head* pHead)
{
	__synapse_structure_cqueue_node*
		ptr_read = NULL;
	
	if (pHead->ptr_cqueue_rdptr->ptr_next 
			== pHead->ptr_cqueue_wrptr)
		return ptr_read;
	
	ptr_read
		= pHead->ptr_cqueue_rdptr;
	pHead->ptr_cqueue_rdptr
		= pHead->ptr_cqueue_rdptr->ptr_next;

	return ptr_read;
}

bool
	__synapse_structure_cqueue_write_to
		(__synapse_structure_cqueue_head* pHead, void* pWrPtr, size_t pWrSize)
{
	if (pHead->ptr_cqueue_wrptr->ptr_next 
			== pHead->ptr_cqueue_rdptr)
		return false;
	
	if(pHead->size_cqueue_node < pWrSize)
		return false;

	memcpy
		(pHead->ptr_cqueue_wrptr->ptr_entity,
			pWrPtr, pWrSize);
	
	return true;
}
