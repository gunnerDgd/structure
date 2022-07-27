#include <structure/queue/spsc/spsc_manip.h>
#include <structure/queue/spsc/details/spsc_queue_manip.h>

synapse_structure_spsc_queue_probe
    synapse_structure_spsc_queue_read_probe
        (synapse_structure_spsc_queue pSpscQueue)
{
    synapse_structure_opaque_handle_init
        (synapse_structure_spsc_queue_probe, hnd_probe,
            __synapse_structure_spsc_queue_read_probe
                (synapse_structure_opaque_handle_reference
                    (pSpscQueue)));
    
    return
        hnd_probe;
}

synapse_structure_spsc_queue_probe
    synapse_structure_spsc_queue_write_probe
        (synapse_structure_spsc_queue pSpscQueue)
{
    synapse_structure_opaque_handle_init
        (synapse_structure_spsc_queue_probe, hnd_probe,
            __synapse_structure_spsc_queue_write_probe
                (synapse_structure_opaque_handle_reference
                    (pSpscQueue)));
    
    return
        hnd_probe;
}

void*
    synapse_structure_spsc_queue_read
        (synapse_structure_spsc_queue       pSpscQueue,
         synapse_structure_spsc_queue_probe pSpscProbe)
{
    return
        __synapse_structure_spsc_queue_read_from
            (synapse_structure_opaque_handle_reference
                (pSpscQueue),
             synapse_structure_opaque_handle_reference
                (pSpscProbe));
}

void*
    synapse_structure_spsc_queue_read_until_success
        (synapse_structure_spsc_queue       pSpscQueue,
         synapse_structure_spsc_queue_probe pSpscProbe)
{
    return
        __synapse_structure_spsc_queue_read_from_until_success
            (synapse_structure_opaque_handle_reference
                (pSpscQueue),
             synapse_structure_opaque_handle_reference
                (pSpscProbe));
}

bool
    synapse_structure_spsc_queue_write
        (synapse_structure_spsc_queue       pSpscQueue,
         synapse_structure_spsc_queue_probe pSpscProbe, 
         void*                              pSpscData, 
         size_t                             pSpscDataSize)
{
    return
        __synapse_structure_spsc_queue_write_to
            (synapse_structure_opaque_handle_reference
                (pSpscQueue),
             synapse_structure_opaque_handle_reference
                (pSpscProbe),
             pSpscData, pSpscDataSize);
}

void
    synapse_structure_spsc_queue_write_until_success
        (synapse_structure_spsc_queue       pSpscQueue,
         synapse_structure_spsc_queue_probe pSpscProbe, 
         void*                              pSpscData , 
         size_t                             pSpscDataSize)
{
    __synapse_structure_spsc_queue_write_to_until_success
        (synapse_structure_opaque_handle_reference
            (pSpscQueue),
         synapse_structure_opaque_handle_reference
            (pSpscProbe),
         pSpscData, pSpscDataSize);
}