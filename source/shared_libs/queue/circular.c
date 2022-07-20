#include <structure/export/queue/circular/circular.h>
#include <structure/queue/circular/circular_queue_init.h>
#include <structure/queue/circular/circular_queue_manip.h>

synapse_circular_queue
    synapse_initialize_circular_queue
        (size_t pNodeSize, size_t pNodeCount)
{
    return
        synapse_structure_circular_queue_initialize
            (pNodeSize, pNodeCount);
}

void
    synapse_cleanup_circular_queue
        (synapse_circular_queue pCQueue)
{
    synapse_structure_circular_queue_cleanup
        (pCQueue);
}

void*
    synapse_read_cicrular_queue
        (synapse_circular_queue pCQueue)
{
    return
        synapse_structure_circular_queue_read_from
            (pCQueue);
}

void*
    synapse_read_cicrular_queue_until_success
        (synapse_circular_queue pCQueue)
{
    return
        synapse_structure_circular_queue_read_from_until_success
            (pCQueue);
}

bool
    synapse_write_cicrular_queue
        (synapse_circular_queue pCQueue, 
         void*                  pCQueueData, 
         size_t                 pCQueueDataSize)
{
    return
        synapse_structure_circular_queue_write_to
            (pCQueue, pCQueueData, pCQueueDataSize);
}

void
    synapse_write_cicrular_queue_until_success
        (synapse_circular_queue pCQueue, 
         void*                  pCQueueData, 
         size_t                 pCQueueDataSize)
{
    synapse_structure_circular_queue_write_to_until_success
        (pCQueue, pCQueueData, pCQueueDataSize);
}