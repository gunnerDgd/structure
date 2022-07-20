#include <structure/queue/spsc/spsc_type.h>

synapse_structure_spsc_queue_probe
    synapse_structure_spsc_queue_read_probe
        (synapse_structure_spsc_queue);

synapse_structure_spsc_queue_probe
    synapse_structure_spsc_queue_write_probe
        (synapse_structure_spsc_queue);

void*
    synapse_structure_spsc_queue_read
        (synapse_structure_spsc_queue,
         synapse_structure_spsc_queue_probe);

void*
    synapse_structure_spsc_queue_read_until_success
        (synapse_structure_spsc_queue,
         synapse_structure_spsc_queue_probe);

bool
    synapse_structure_spsc_queue_write
        (synapse_structure_spsc_queue,
         synapse_structure_spsc_queue_probe, void*, size_t);

void
    synapse_structure_spsc_queue_write_until_success
        (synapse_structure_spsc_queue,
         synapse_structure_spsc_queue_probe, void*, size_t);