#include <structure/queue/mpmc/mpmc_type.h>
#include <stdbool.h>

void*
    synapse_structure_mpmc_queue_read_from
        (synapse_structure_mpmc_queue);

bool
    synapse_structure_mpmc_queue_write_to
        (synapse_structure_mpmc_queue, void*);

void*
    synapse_structure_mpmc_queue_read_from_until_success
        (synapse_structure_mpmc_queue);

void
    synapse_structure_mpmc_queue_write_to_until_success
        (synapse_structure_mpmc_queue, void*);