#include <structure/queue/mpmc/details/mpmc_queue_manip.h>
#include <Windows.h>

void*
    __synapse_structure_mpmc_queue_read_from
        (__synapse_structure_mpmc_queue* pMpmcQueue)
{
    void*
        ptr_read;
    
    if(!InterlockedXor64
            (pMpmcQueue->ptr_mpmc_rdptr->ptr_mpmc_next, 
                pMpmcQueue->ptr_mpmc_wrptr))
                    return NULL;

    ptr_read
        = InterlockedCompareExchange64
                (&pMpmcQueue->ptr_mpmc_rdptr->ptr_mpmc_data,
                    0, pMpmcQueue->ptr_mpmc_rdptr->ptr_mpmc_data);
    
    if(!ptr_read) 
        return NULL;
    while
        (pMpmcQueue->ptr_mpmc_rdptr
            != InterlockedCompareExchange64
                    (&pMpmcQueue->ptr_mpmc_rdptr,
                        pMpmcQueue->ptr_mpmc_rdptr->ptr_mpmc_next,
                            pMpmcQueue->ptr_mpmc_rdptr));
    
    return
        ptr_read;
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
    void*
        ptr_mpmc_data;

    if(!InterlockedXor64
            (pMpmcQueue->ptr_mpmc_wrptr,
                pMpmcQueue->ptr_mpmc_rdptr))
                    return false;

    ptr_mpmc_data
        = InterlockedCompareExchange64
                (&pMpmcQueue->ptr_mpmc_wrptr->ptr_mpmc_data,
                    pMpmcData, 0);
    
    if(ptr_mpmc_data)
        return false;
    
    while
        (pMpmcQueue->ptr_mpmc_wrptr
            != InterlockedCompareExchange64
                    (&pMpmcQueue->ptr_mpmc_wrptr,
                        pMpmcQueue->ptr_mpmc_wrptr->ptr_mpmc_next,
                            pMpmcQueue->ptr_mpmc_wrptr));
    
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