#include <structure/queue/mpmc/details/mpmc_queue_manip.h>
#include <Windows.h>

void*
    __synapse_structure_mpmc_queue_read_from
        (__synapse_structure_mpmc_queue* pMpmcQueue)
{
    __synapse_structure_mpmc_queue_node*
        ptr_read;
    
    if(ptr_read->ptr_mpmc_next
            == pMpmcQueue->ptr_mpmc_wrptr)
                return NULL;

    do
    {
        ptr_read
            = pMpmcQueue->ptr_mpmc_rdptr;
    } while
        (InterlockedCompareExchange64
            (&pMpmcQueue->ptr_mpmc_rdptr,
                pMpmcQueue->ptr_mpmc_rdptr->ptr_mpmc_next,
                    ptr_read) != ptr_read);
    
    return
        ptr_read->ptr_mpmc_data;
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
    void
        *ptr_write;
    
    if(pMpmcQueue->ptr_mpmc_wrptr->ptr_mpmc_next
            != pMpmcQueue->ptr_mpmc_rdptr)
                    return false;

    do
    {
        ptr_write
            = pMpmcQueue->ptr_mpmc_wrptr->ptr_mpmc_data;
    } while(ptr_write 
                != InterlockedCompareExchange64
                        (&pMpmcQueue->ptr_mpmc_wrptr->ptr_mpmc_data,
                            pMpmcData, ptr_write));

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