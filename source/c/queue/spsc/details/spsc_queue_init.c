#include <structure/queue/spsc/details/spsc_queue_init.h>
#include <synapse/memory/memory.h>

__synapse_structure_spsc_queue*
    __synapse_structure_spsc_queue_initialize
        (size_t pSpscNodeSize, size_t pSpscNodeCount)
{
    __synapse_structure_spsc_queue*
        ptr_spsc
            = synapse_system_allocate
                    (sizeof(__synapse_structure_spsc_queue));
    
    ptr_spsc->ptr_spsc_arena
        = synapse_system_allocate
                (pSpscNodeCount* pSpscNodeSize);
    ptr_spsc->ptr_spsc_node
        = synapse_system_allocate
                (pSpscNodeCount * sizeof(__synapse_structure_spsc_queue_node));

    for(size_t it_init = 0;
               it_init < pSpscNodeCount - 1 ;
               it_init++)
    {
        ptr_spsc->ptr_spsc_node[it_init].ptr_node_next
            = &ptr_spsc->ptr_spsc_node[it_init + 1];
        ptr_spsc->ptr_spsc_node[it_init].ptr_node_data
            = (uint8_t*)ptr_spsc->ptr_spsc_arena
                    + it_init * pSpscNodeSize;
    }

    ptr_spsc->ptr_spsc_node[pSpscNodeCount - 1].ptr_node_next
        = ptr_spsc->ptr_spsc_node;
    ptr_spsc->ptr_spsc_node[pSpscNodeCount - 1].ptr_node_data
        = (uint8_t*)ptr_spsc->ptr_spsc_arena
                + pSpscNodeSize * (pSpscNodeCount - 1);
    
    ptr_spsc->prb_spsc_read.ptr_probe_access
        = ptr_spsc->ptr_spsc_node;
    ptr_spsc->prb_spsc_read.pid_probe
        = 0;

    ptr_spsc->prb_spsc_write.ptr_probe_access
        = ptr_spsc->ptr_spsc_node->ptr_node_next;
    ptr_spsc->prb_spsc_write.pid_probe
        = 0;

    return
        ptr_spsc;
}

void
    __synapse_structure_spsc_queue_cleanup
        (__synapse_structure_spsc_queue* pSpscQueue)
{
    synapse_system_deallocate
        (pSpscQueue->ptr_spsc_node);
    synapse_system_deallocate
        (pSpscQueue->ptr_spsc_arena);
    synapse_system_deallocate
        (pSpscQueue);
}