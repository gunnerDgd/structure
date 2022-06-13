#include <structure/queue/circular/circular_queue_manip.h>
#include <structure/details/queue/circular/cqueue_manip.h>

void
synapse_structure_circular_queue_read_from(synapse_structure_circular_queue pQueue, void* pData, size_t pDataSize)
{
	__synapse_structure_cqueue_read_from(pQueue.opaque, pData, pDataSize);
}

void
synapse_structure_circular_queue_write_to(synapse_structure_circular_queue pQueue, void* pData, size_t pDataSize)
{
	__synapse_structure_cqueue_write_to(pQueue.opaque, pData, pDataSize);
}

synapse_structure_circular_queue_node
synapse_structure_circular_queue_read_pointer(synapse_structure_circular_queue pQueue)
{
	synapse_structure_circular_queue_node ptr_rdptr
		= { .opaque = __synapse_structure_cqueue_rdptr(pQueue.opaque) };

	return ptr_rdptr;
}

synapse_structure_circular_queue_node
synapse_structure_circular_queue_write_pointer(synapse_structure_circular_queue pQueue)
{
	synapse_structure_circular_queue_node ptr_wrptr
		= { .opaque = __synapse_structure_cqueue_wrptr(pQueue.opaque) };

	return ptr_wrptr;
}