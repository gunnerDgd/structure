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
        // Retrieves Read Pointer of MPMC Circular Queue
        ptr_read 
            = pMpmcQueue->ptr_mpmc_rdptr;
        // Retrieves Read Data from Read Pointer. This Might be NULL or Actual Data
        ptr_read_data
            = ptr_read->ptr_mpmc_data; 
        
        // If There's no data to read (read_pointer == write_pointer),
        // routine exits with return value 0.
        if(ptr_read_data == NULL
                || ptr_read == pMpmcQueue->ptr_mpmc_wrptr)
                        return 0;
    }
    while
        (!InterlockedCompareExchange64
            (&ptr_read->ptr_mpmc_data, 0, ptr_read_data));
    /*CAS with Read Pointer's Data.
     * Only one thread can success this operation.
     *
     * Read Data == 0 -> The Read Pointer is already read by other thread.
     * Read Data != 0 -> Read - Available State.
     * 
     * CAS -> Change Read Pointer's Data Pointer to NULL,
     * To Specify other thread cannot read data from this pointer.
     * 
     * If ptr_read_data == 0, cmpxchg intrinsic (InterlockedCompareExchange) will return NULL,
     */ 
    
    InterlockedExchange64
        (&pMpmcQueue->ptr_mpmc_rdptr,
                ptr_read->ptr_mpmc_next);
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
    
    InterlockedExchange64
        (&pMpmcQueue->ptr_mpmc_wrptr,
                ptr_write->ptr_mpmc_next);

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