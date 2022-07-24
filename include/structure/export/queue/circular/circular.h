#include <structure/export/interface/queue/circular.h>
#include <structure/defines/export/export.h>

#include <stdbool.h>

synapse_structure_dll
    synapse_circular_queue
        synapse_initialize_circular_queue
            (size_t, size_t);

synapse_structure_dll
    void
        synapse_cleanup_circular_queue
            (synapse_circular_queue);

synapse_structure_dll
    void*
        synapse_read_cicrular_queue
            (synapse_circular_queue);

synapse_structure_dll
    void*
        synapse_read_cicrular_queue_until_success
            (synapse_circular_queue);

synapse_structure_dll
    bool
        synapse_write_cicrular_queue
            (synapse_circular_queue, void*, size_t);

synapse_structure_dll
    void
        synapse_write_cicrular_queue_until_success
            (synapse_circular_queue, void*, size_t);