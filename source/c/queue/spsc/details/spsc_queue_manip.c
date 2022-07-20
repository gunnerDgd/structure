#include <structure/queue/spsc/details/spsc_queue_manip.h>
#include <Windows.h>

__synapse_structure_spsc_queue_probe*
    __synapse_structure_spsc_queue_read_probe
        (__synapse_structure_spsc_queue* pSpscQueue)
{
    if(pSpscQueue->prb_spsc_read.pid_probe)
        return NULL;
    
    pSpscQueue->prb_spsc_read.pid_probe
        = GetCurrentThreadId();
    return
        &pSpscQueue->prb_spsc_read;
}

__synapse_structure_spsc_queue_probe*
    __synapse_structure_spsc_queue_write_probe
        (__synapse_structure_spsc_queue* pSpscQueue)
{
    if(pSpscQueue->prb_spsc_write.pid_probe)
        return NULL;
    
    pSpscQueue->prb_spsc_write.pid_probe
        = GetCurrentThreadId();
    return
        &pSpscQueue->prb_spsc_write;
}

void*
    __synapse_structure_spsc_queue_read_from
        (__synapse_structure_spsc_queue*       pSpscQueue,
         __synapse_structure_spsc_queue_probe* pSpscProbe)
{
    __synapse_structure_spsc_queue_node*
        ptr_read
            = pSpscProbe->ptr_probe_access;
    
    if(pSpscProbe->ptr_probe_access->ptr_node_next
            == pSpscQueue->prb_spsc_write.ptr_probe_access)
                return NULL;
    else
        InterlockedExchange64
            (&pSpscProbe->ptr_probe_access,
                pSpscProbe->ptr_probe_access->ptr_node_next);
    
    return
        ptr_read->ptr_node_data;
}

void*
    __synapse_structure_spsc_queue_read_from_until_success
        (__synapse_structure_spsc_queue*       pSpscQueue,
         __synapse_structure_spsc_queue_probe* pSpscProbe)
{
    void*
        ptr_read;
    while
        (!(ptr_read
                = __synapse_structure_spsc_queue_read_from
                        (pSpscQueue, pSpscProbe)));
    
    return
        ptr_read;
}

bool
    __synapse_structure_spsc_queue_write_to
        (__synapse_structure_spsc_queue*       pSpscQueue,
         __synapse_structure_spsc_queue_probe* pSpscProbe, 
         void*                                 pData, 
         size_t                                pDataSize)
{
    __synapse_structure_spsc_queue_node*
        ptr_write
            = pSpscProbe->ptr_probe_access;
    
    if(pSpscProbe->ptr_probe_access->ptr_node_next
            == pSpscQueue->prb_spsc_read.ptr_probe_access)
                return false;

    memcpy
        (ptr_write->ptr_node_data, pData, pDataSize);
    InterlockedExchange64
        (&pSpscProbe->ptr_probe_access,
            pSpscProbe->ptr_probe_access->ptr_node_next);

    return true;
}

void
    __synapse_structure_spsc_queue_write_to_until_success
        (__synapse_structure_spsc_queue*       pSpscQueue, 
         __synapse_structure_spsc_queue_probe* pSpscProbe, 
         void*                                 pData     , 
         size_t                                pDataSize)
{
    while
        (!__synapse_structure_spsc_queue_write_to
            (pSpscQueue, pSpscProbe, pData, pDataSize));
}