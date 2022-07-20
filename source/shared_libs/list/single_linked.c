#include <structure/export/list/single_linked.h>
#include <structure/list/single_linked.h>

synapse_structure_dll
    synapse_single_linked
        synapse_initialize_single_linked
            (synapse_memory_manager* pMman)
{
    return
        synapse_structure_single_linked_initialize
            (pMman);
}

synapse_structure_dll
    void
        synapse_cleanup_single_linked
            (synapse_single_linked pSingleLinked)
{
    synapse_structure_single_linked_cleanup
        (pSingleLinked);
}

synapse_structure_dll
    void
        synapse_single_linked_push
            (synapse_single_linked pSingleLinked, 
             void*                 pData, 
             size_t                pDataSize)
{
    synapse_structure_single_linked_push
        (pSingleLinked, pData, pDataSize);
}

synapse_structure_dll
    void*
        synapse_single_linked_pop
            (synapse_single_linked pSingleLinked)
{
    return
        synapse_structure_single_linked_pop
            (pSingleLinked);
}

synapse_structure_dll
    void*
        synapse_single_linked_pop_until_success
            (synapse_single_linked pSingleLinked)
{
    return
        synapse_structure_single_linked_pop_until_success
            (pSingleLinked);
}

synapse_structure_dll
    synapse_single_linked_node
        synapse_single_linked_peek
            (synapse_single_linked pSingleLinked)
{
    return
        synapse_structure_single_linked_peek
            (pSingleLinked);
}