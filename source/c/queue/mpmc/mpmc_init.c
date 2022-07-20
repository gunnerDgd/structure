#include <structure/queue/mpmc/mpmc_init.h>
#include <structure/queue/mpmc/details/mpmc_queue_init.h>

synapse_structure_mpmc_queue
    synapse_structure_mpmc_queue_initialize
        (size_t pMpmcCount)
{
    synapse_structure_opaque_handle_init
        (synapse_structure_mpmc_queue, hnd_mpmc,
            __synapse_structure_mpmc_queue_initialize
                (pMpmcCount));
    
    return hnd_mpmc;
}

void
    synapse_structure_mpmc_queue_cleanup
        (synapse_structure_mpmc_queue pMpmcQueue)
{
    __synapse_structure_mpmc_queue_cleanup
        (synapse_structure_opaque_handle_reference
            (pMpmcQueue));
}