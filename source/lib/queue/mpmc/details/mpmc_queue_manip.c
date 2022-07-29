#include <structure/queue/mpmc/details/mpmc_queue_manip.h>
#include <Windows.h>

void*
    __synapse_structure_mpmc_queue_read_from
        (__synapse_structure_mpmc_queue* pMpmcQueue)
{
    __synapse_structure_mpmc_queue_node*
        ptr_read;
    void*
        ptr_read_data;

    do
    {
        ptr_read
            = pMpmcQueue->ptr_mpmc_rdptr;
        ptr_read_data
            = ptr_read->ptr_mpmc_data;

        if(!ptr_read_data)
            return 0;
        if(ptr_read == pMpmcQueue->ptr_mpmc_wrptr)
                 return 0;
    }
    while
        (ptr_read_data !=
                InterlockedCompareExchange64
                    (&ptr_read->ptr_mpmc_data, 0, ptr_read->ptr_mpmc_data));
    
    while
        (ptr_read
            != InterlockedCompareExchange64
                    (&pMpmcQueue->ptr_mpmc_rdptr,
                        ptr_read->ptr_mpmc_next, ptr_read));
    
    return
        ptr_read_data;
}

void*
    __synapse_structure_mpmc_queue_read_from_until_success
        (__synapse_structure_mpmc_queue* pMpmcQueue)
{
    void*
        ptr_read;
    
    while
        (!(ptr_read
            = __synapse_structure_mpmc_queue_read_from
                    (pMpmcQueue)));
    
    return ptr_read;

}

bool
    __synapse_structure_mpmc_queue_write_to
        (__synapse_structure_mpmc_queue* pMpmcQueue, void* pMpmcData)
{
    __synapse_structure_mpmc_queue_node*
        ptr_write;

    do
    {
        ptr_write
            = pMpmcQueue->ptr_mpmc_wrptr;
        if(ptr_write->ptr_mpmc_next
                == pMpmcQueue->ptr_mpmc_rdptr)
                        return false;
    }
    while
        (InterlockedCompareExchange64
                (&ptr_write->ptr_mpmc_data, pMpmcData, 0));
    
    while
        (ptr_write
            != InterlockedCompareExchange64
                    (&pMpmcQueue->ptr_mpmc_wrptr,
                        ptr_write->ptr_mpmc_next, ptr_write));

    return true;
}

void
    __synapse_structure_mpmc_queue_write_to_until_success
        (__synapse_structure_mpmc_queue* pMpmcQueue, void* pMpmcData)
{
    while
        (!__synapse_structure_mpmc_queue_write_to
            (pMpmcQueue, pMpmcData));
}