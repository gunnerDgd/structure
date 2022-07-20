#include <structure/defines/handle/opaque_handle.h>
#include <structure/defines/export/export.h>

#include <structure/export/interface/list/single_linked.h>

#include <synapse/memory/memory.h>

synapse_structure_dll
    synapse_single_linked
        synapse_initialize_single_linked
            (synapse_memory_manager*);

synapse_structure_dll
    void
        synapse_cleanup_single_linked
            (synapse_single_linked);

synapse_structure_dll
    void
        synapse_single_linked_push
            (synapse_single_linked, void*, size_t);

synapse_structure_dll
    void*
        synapse_single_linked_pop
            (synapse_single_linked);

synapse_structure_dll
    void*
        synapse_single_linked_pop_until_success
            (synapse_single_linked);

synapse_structure_dll
    synapse_single_linked_node
        synapse_single_linked_peek
            (synapse_single_linked);