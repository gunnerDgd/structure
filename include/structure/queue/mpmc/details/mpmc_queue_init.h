#include <structure/queue/mpmc/details/mpmc_queue_type.h>

__synapse_structure_mpmc_queue*
    __synapse_structure_mpmc_queue_initialize
        (size_t);

void
    __synapse_structure_mpmc_queue_cleanup
        (__synapse_structure_mpmc_queue*);