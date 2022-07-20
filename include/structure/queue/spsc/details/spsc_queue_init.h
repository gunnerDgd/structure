#include <structure/queue/spsc/details/spsc_queue_type.h>

__synapse_structure_spsc_queue*
    __synapse_structure_spsc_queue_initialize
        (size_t, size_t);

void
    __synapse_structure_spsc_queue_cleanup
        (__synapse_structure_spsc_queue*);