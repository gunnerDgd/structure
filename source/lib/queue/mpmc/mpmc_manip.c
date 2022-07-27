#include <structure/queue/mpmc/mpmc_manip.h>
#include <structure/queue/mpmc/details/mpmc_queue_manip.h>

void*
    synapse_structure_mpmc_queue_read_from
        (synapse_structure_mpmc_queue pMpmcQueue)
{
    return
        __synapse_structure_mpmc_queue_read_from
            (synapse_structure_opaque_handle_reference
                (pMpmcQueue));
}

bool
    synapse_structure_mpmc_queue_write_to
        (synapse_structure_mpmc_queue pMpmcQueue, void* pMpmcData)
{
    return
        __synapse_structure_mpmc_queue_write_to
            (synapse_structure_opaque_handle_reference
                (pMpmcQueue), pMpmcData);
}

void*
    synapse_structure_mpmc_queue_read_from_until_success
        (synapse_structure_mpmc_queue pMpmcQueue)
{
    return
        __synapse_structure_mpmc_queue_read_from_until_success
            (synapse_structure_opaque_handle_reference
                (pMpmcQueue));
}

void
    synapse_structure_mpmc_queue_write_to_until_success
        (synapse_structure_mpmc_queue pMpmcQueue, void* pMpmcData)
{
    __synapse_structure_mpmc_queue_write_to
        (synapse_structure_opaque_handle_reference
            (pMpmcQueue), pMpmcData);
}