#include <structure/queue/spsc/spsc_init.h>
#include <structure/queue/spsc/details/spsc_queue_init.h>

synapse_structure_spsc_queue
    synapse_structure_spsc_queue_initialize
        (size_t pSpscNodeSize, size_t pSpscNodeCount)
{
    synapse_structure_opaque_handle_init
        (synapse_structure_spsc_queue, hnd_spsc,
            __synapse_structure_spsc_queue_initialize
                (pSpscNodeSize, pSpscNodeCount));
    
    return
        hnd_spsc;
}

void
    synapse_structure_spsc_queue_cleanup
        (synapse_structure_spsc_queue pSpscQueue)
{
    __synapse_structure_spsc_queue_cleanup
        (synapse_structure_opaque_handle_reference
            (pSpscQueue));
}