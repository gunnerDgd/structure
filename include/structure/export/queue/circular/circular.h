#include <structure/export/interface/queue/circular.h>
#include <stdbool.h>

synapse_circular_queue
    synapse_initialize_circular_queue
        (size_t, size_t);

void
    synapse_cleanup_circular_queue
        (synapse_circular_queue);

void*
    synapse_read_cicrular_queue
        (synapse_circular_queue);

void*
    synapse_read_cicrular_queue_until_success
        (synapse_circular_queue);

bool
    synapse_write_cicrular_queue
        (synapse_circular_queue, void*, size_t);

void
    synapse_write_cicrular_queue_until_success
        (synapse_circular_queue, void*, size_t);