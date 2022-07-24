#pragma once
#include <structure/queue/mpmc/mpmc_type.h>

synapse_structure_mpmc_queue
    synapse_structure_mpmc_queue_initialize
        (size_t);

void
    synapse_structure_mpmc_queue_cleanup
        (synapse_structure_mpmc_queue);