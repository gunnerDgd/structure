#include <structure/export/queue/lockfree/spsc.h>

#include <structure/queue/spsc/spsc_init.h>
#include <structure/queue/spsc/spsc_manip.h>

synapse_structure_dll
    synapse_spsc_queue
        synapse_initialize_spsc_queue
            (size_t pSpscNodeSize, size_t pSpscNodeCount)
{
    return
        synapse_structure_spsc_queue_initialize
            (pSpscNodeSize, pSpscNodeCount);
}

synapse_structure_dll
    void
        synapse_cleanup_spsc_queue
            (synapse_spsc_queue pSpscQueue)
{
    synapse_structure_spsc_queue_cleanup
        (pSpscQueue);
}

synapse_structure_dll
    synapse_spsc_probe
        synapse_spsc_queue_read_probe
            (synapse_spsc_queue pSpscQueue)
{
    return
        synapse_structure_spsc_queue_read_probe
            (pSpscQueue);
}

synapse_structure_dll
    synapse_spsc_probe
        synapse_spsc_queue_write_probe
            (synapse_spsc_queue pSpscQueue)
{
    return
        synapse_structure_spsc_queue_write_probe
            (pSpscQueue);
}

synapse_structure_dll
    void*
        synapse_read_spsc_queue
            (synapse_spsc_queue pSpscQueue, synapse_spsc_probe pSpscProbe)
{
    return
        synapse_structure_spsc_queue_read
            (pSpscQueue, pSpscProbe);
}

synapse_structure_dll
    void*
        synapse_read_spsc_queue_until_success
            (synapse_spsc_queue pSpscQueue, synapse_spsc_probe pSpscProbe)
{
    return
        synapse_structure_spsc_queue_read_until_success
            (pSpscQueue, pSpscProbe);
}

synapse_structure_dll
    bool
        synapse_write_spsc_queue
            (synapse_spsc_queue pSpscQueue, synapse_spsc_probe pSpscProbe,
                void* pSpscData, size_t pSpscDataSize)
{
    return
        synapse_structure_spsc_queue_write
            (pSpscQueue, pSpscProbe, pSpscData, pSpscDataSize);
}

synapse_structure_dll
    void
        synapse_write_spsc_queue_until_success
            (synapse_spsc_queue pSpscQueue, synapse_spsc_probe pSpscProbe,
                void* pSpscData, size_t pSpscDataSize)
{
    return
        synapse_structure_spsc_queue_write_until_success
            (pSpscQueue, pSpscProbe, pSpscData, pSpscDataSize);
}