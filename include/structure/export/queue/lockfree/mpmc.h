#include <structure/export/interface/queue/mpmc.h>
#include <structure/defines/export/export.h>

#include <stdbool.h>

synapse_structure_dll
    synapse_mpmc_queue
        synapse_initialize_mpmc_queue
            (size_t);

synapse_structure_dll
    void
        synapse_cleanup_mpmc_queue
            (synapse_mpmc_queue);

synapse_structure_dll
    void*
        synapse_read_mpmc_queue
            (synapse_mpmc_queue);

synapse_structure_dll
    void*
        synapse_read_mpmc_queue_until_success
            (synapse_mpmc_queue);

synapse_structure_dll
    bool
        synapse_write_mpmc_queue
            (synapse_mpmc_queue, void*);

synapse_structure_dll
    void
        synapse_write_mpmc_queue_until_success
            (synapse_mpmc_queue, void*);