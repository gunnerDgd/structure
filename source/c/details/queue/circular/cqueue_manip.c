#include <structure/details/queue/circular/cqueue_init.h>
#include <string.h>

void
__synapse_structure_cqueue_read_from
	(__synapse_structure_cqueue_head* pHead, void* pRdPtr, size_t pRdSize)
{
	if (pHead->rdptr->next == pHead->wrptr)
		return;

	memcpy(pRdPtr, pHead->rdptr->ptr_entity, (pRdSize > pHead->node_size) ? pHead->node_size : pRdSize);
	pHead->rdptr = pHead->rdptr->next;
}

void
__synapse_structure_cqueue_write_to(__synapse_structure_cqueue_head* pHead, void* pWrPtr, size_t pWrSize)
{
	if (pHead->wrptr->next == pHead->rdptr)
		return;

	memcpy(pHead->wrptr->ptr_entity, pWrPtr, (pWrSize > pHead->node_size) ? pHead->node_size : pWrSize);
		   pHead->wrptr = pHead->wrptr->next;
}

__synapse_structure_cqueue_node*
__synapse_structure_cqueue_rdptr(__synapse_structure_cqueue_head* pHead) { return pHead->rdptr; }

__synapse_structure_cqueue_node*
__synapse_structure_cqueue_wrptr(__synapse_structure_cqueue_head* pHead) { return pHead->wrptr; }