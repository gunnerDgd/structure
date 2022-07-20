#include <structure/export/list/double_linked.h>
#include <structure/list/double_linked.h>

synapse_structure_dll
    synapse_double_linked
        synapse_initialize_double_linked
            (synapse_memory_manager* pMman)
{
    return
        synapse_structure_double_linked_initialize
            (pMman);
}

synapse_structure_dll
    void
        synapse_cleanup_double_linked
            (synapse_double_linked pDoubleLinked)
{
    synapse_structure_double_linked_cleanup
        (pDoubleLinked);
}

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_at
            (synapse_double_linked      pDoubleLinked, 
             synapse_double_linked_node pDoubleLinkedNode, 
             void*                      pData, 
             size_t                     pDataSize)
{
    return
        synapse_structure_double_linked_insert_at
            (pDoubleLinked, pDoubleLinkedNode, pData, pDataSize);
}

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_front
            (synapse_double_linked pDoubleLinked,
             void*                 pData, 
             size_t                pDataSize)
{
    return
        synapse_structure_double_linked_insert_front
            (pDoubleLinked, pData, pDataSize);
}

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_insert_back
            (synapse_double_linked pDoubleLinked, 
             void*                 pData, 
             size_t                pDataSize)
{
    return
        synapse_structure_double_linked_insert_back
            (pDoubleLinked, pData, pDataSize);
}

synapse_structure_dll
    void
        synapse_double_linked_erase_at
            (synapse_double_linked      pDoubleLinked, 
             synapse_double_linked_node pDoubleLinkedNode)
{
    synapse_structure_double_linked_erase_at
        (pDoubleLinked, pDoubleLinkedNode);
}

synapse_structure_dll
    void
        synapse_double_linked_erase_front
            (synapse_double_linked pDoubleLinked)
{
    synapse_structure_double_linked_erase_front
        (pDoubleLinked);
}

synapse_structure_dll
    void
        synapse_double_linked_erase_back
            (synapse_double_linked pDoubleLinked)
{
    synapse_structure_double_linked_erase_back
        (pDoubleLinked);
}

synapse_structure_dll
    void*
        synapse_double_linked_node_data
            (synapse_double_linked_node pDoubleLinkedNode)
{
    return
        synapse_structure_double_linked_node_data
            (pDoubleLinkedNode);
}

synapse_structure_dll
    size_t
        synapse_double_linked_node_size
            (synapse_double_linked_node pDoubleLinkedNode)
{
    return
        synapse_structure_double_linked_node_size
            (pDoubleLinkedNode);
}

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_node_next
            (synapse_double_linked_node pDoubleLinkedNode)
{
    return
        synapse_structure_double_linked_node_next
            (pDoubleLinkedNode);
}

synapse_structure_dll
    synapse_double_linked_node
        synapse_double_linked_node_prev
            (synapse_double_linked_node pDoubleLinkedNode)
{
    return
        synapse_structure_double_linked_node_prev
            (pDoubleLinkedNode);
}