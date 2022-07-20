#include <structure/defines/handle/opaque_handle.h>
#include <structure/defines/export/export.h>

#include <structure/export/interface/list/double_linked.h>

#include <synapse/memory/memory.h>

synapse_structure_dll
    synapse_double_linked
        synapse_initialize_double_linked
            (synapse_memory_manager*);

synapse_structure_dll
    void
        synapse_cleanup_double_linked
            (synapse_double_linked);

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_at
            (synapse_double_linked, synapse_double_linked_node, void*, size_t);

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_front
            (synapse_double_linked, void*, size_t);

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_back
            (synapse_double_linked, void*, size_t);

synapse_structure_dll
    void
        synapse_double_linked_erase_at
            (synapse_double_linked, synapse_double_linked_node);

synapse_structure_dll
    void
        synapse_double_linked_erase_front
            (synapse_double_linked);

synapse_structure_dll
    void
        synapse_double_linked_erase_back
            (synapse_double_linked);

synapse_structure_dll
    void*
        synapse_double_linked_node_data
            (synapse_double_linked_node);

synapse_structure_dll
    size_t
        synapse_double_linked_node_size
            (synapse_double_linked_node);

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_node_next
            (synapse_double_linked_node);

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_node_prev
            (synapse_double_linked_node);