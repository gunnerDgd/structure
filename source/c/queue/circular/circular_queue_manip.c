#include <structure/queue/circular/circular_queue_manip.h>
#include <structure/details/queue/circular/cqueue_manip.h>

void*
    synapse_structure_circular_queue_read_from
        (synapse_structure_circular_queue pCqueue)
{
	__synapse_structure_cqueue_node*
		ptr_rdptr
			= __synapse_structure_cqueue_read_from
					(synapse_structure_opaque_handle_reference
						(pCqueue));

	return
		(ptr_rdptr) ? ptr_rdptr->ptr_entity
					: NULL;
}

bool
    synapse_structure_circular_queue_write_to 
        (synapse_structure_circular_queue pCqueue, 
		 void*							  pWriteData, 
		 size_t							  pWriteDataSize)
{
	return
		__synapse_structure_cqueue_write_to
			(synapse_structure_opaque_handle_reference
				(pCqueue), pWriteData, pWriteDataSize);
}

void*
    synapse_structure_circular_queue_read_from_until_success
        (synapse_structure_circular_queue pCqueue)
{
	void*
		ptr_read_data
			= NULL;
	
	while(!(ptr_read_data
				= synapse_structure_circular_queue_read_from
						(pCqueue)));
	
	return
		ptr_read_data;
}

void
    synapse_structure_circular_queue_write_to_until_success
        (synapse_structure_circular_queue pCqueue, 
		 void*							  pCqueueData, 
		 size_t							  pCqueueDataSize)
{
	while
		(!synapse_structure_circular_queue_write_to
			(pCqueue, pCqueueData, pCqueueDataSize));
}