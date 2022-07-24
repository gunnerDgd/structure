#include <structure/export/queue/lockfree/mpmc.h>

#include <structure/queue/mpmc/mpmc_init.h>
#include <structure/queue/mpmc/mpmc_manip.h>

synapse_structure_dll
    synapse_mpmc_queue
        synapse_initialize_mpmc_queue
            (size_t pMpmcNodeCount)
{
    return
        synapse_structure_mpmc_queue_initialize
            (pMpmcNodeCount);
}

synapse_structure_dll
    void
        synapse_cleanup_mpmc_queue
            (synapse_mpmc_queue pMpmcQueue)
{
    synapse_structure_mpmc_queue_cleanup
        (pMpmcQueue);
}

synapse_structure_dll
    void*
        synapse_read_mpmc_queue
            (synapse_mpmc_queue pMpmcQueue)
{
    return
        synapse_structure_mpmc_queue_read_from
            (pMpmcQueue);
}

synapse_structure_dll
    void*
        synapse_read_mpmc_queue_until_success
            (synapse_mpmc_queue pMpmcQueue)
{
    return
        synapse_structure_mpmc_queue_read_from_until_success
            (pMpmcQueue);
}

synapse_structure_dll
    bool
        synapse_write_mpmc_queue
            (synapse_mpmc_queue pMpmcQueue, void* pMpmcData)
{
    return
        synapse_structure_mpmc_queue_write_to
            (pMpmcQueue, pMpmcData);
}

synapse_structure_dll
    void
        synapse_write_mpmc_queue_until_success
            (synapse_mpmc_queue pMpmcQueue, void* pMpmcData)
{
    synapse_structure_mpmc_queue_write_to_until_success
        (pMpmcQueue, pMpmcData);
}