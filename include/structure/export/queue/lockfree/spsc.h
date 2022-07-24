#pragma once

#include <structure/export/interface/queue/spsc.h>
#include <structure/defines/export/export.h>

#include <stdbool.h>

synapse_structure_dll
    synapse_spsc_queue
        synapse_initialize_spsc_queue
            (size_t, size_t);

synapse_structure_dll
    void
        synapse_cleanup_spsc_queue
            (synapse_spsc_queue);

synapse_structure_dll
    synapse_spsc_probe
        synapse_spsc_queue_read_probe
            (synapse_spsc_queue);

synapse_structure_dll
    synapse_spsc_probe
        synapse_spsc_queue_write_probe
            (synapse_spsc_queue);

synapse_structure_dll
    void*
        synapse_read_spsc_queue
            (synapse_spsc_queue, synapse_spsc_probe);

synapse_structure_dll
    void*
        synapse_read_spsc_queue_until_success
            (synapse_spsc_queue, synapse_spsc_probe);

synapse_structure_dll
    bool
        synapse_write_spsc_queue
            (synapse_spsc_queue, synapse_spsc_probe, void*, size_t);

synapse_structure_dll
    void
        synapse_write_spsc_queue_until_success
            (synapse_spsc_queue, synapse_spsc_probe, void*, size_t);