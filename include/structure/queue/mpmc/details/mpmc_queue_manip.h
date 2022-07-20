#include <structure/queue/mpmc/details/mpmc_queue_type.h>
#include <stdbool.h>

void*
    __synapse_structure_mpmc_queue_read_from
        (__synapse_structure_mpmc_queue*);

void*
    __synapse_structure_mpmc_queue_read_from_until_success
        (__synapse_structure_mpmc_queue*);

bool
    __synapse_structure_mpmc_queue_write_to
        (__synapse_structure_mpmc_queue*, void*);

void
    __synapse_structure_mpmc_queue_write_to_until_success
        (__synapse_structure_mpmc_queue*, void*);