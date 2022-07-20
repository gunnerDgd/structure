#include <structure/queue/mpmc/details/mpmc_queue_init.h>
#include <synapse/memory/memory.h>

__synapse_structure_mpmc_queue*
    __synapse_structure_mpmc_queue_initialize
        (size_t pMpmcNodeCount)
{
    __synapse_structure_mpmc_queue*
        ptr_mpmc
            = synapse_system_allocate
                (sizeof(__synapse_structure_mpmc_queue));

    ptr_mpmc->ptr_mpmc_node
        = synapse_system_allocate
            (pMpmcNodeCount * sizeof(__synapse_structure_mpmc_queue_node));
    
    for(size_t it_init = 0;
               it_init < pMpmcNodeCount - 1;
               it_init++)
                    ptr_mpmc->ptr_mpmc_node[it_init].ptr_mpmc_next
                        = &ptr_mpmc->ptr_mpmc_node[it_init + 1];
    
    ptr_mpmc->ptr_mpmc_rdptr
        = ptr_mpmc->ptr_mpmc_node;
    ptr_mpmc->ptr_mpmc_wrptr
        = ptr_mpmc->ptr_mpmc_node->ptr_mpmc_next;

    return
        ptr_mpmc;
}

void
    __synapse_structure_mpmc_queue_cleanup
        (__synapse_structure_mpmc_queue* pMpmcQueue)
{
    synapse_system_deallocate
        (pMpmcQueue->ptr_mpmc_node);
    synapse_system_deallocate
        (pMpmcQueue);
}