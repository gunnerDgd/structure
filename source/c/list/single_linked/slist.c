#include <structure/list/single_linked.h>

#include <structure/details/list/single_linked/slist_init.h>
#include <structure/details/list/single_linked/slist_manip.h>


synapse_structure_single_linked
	synapse_structure_single_linked_initialize
		(synapse_memory_manager* pMman)
{
	synapse_structure_opaque_handle_init
		(synapse_structure_single_linked, hnd_slist,
			__synapse_structure_slist_initialize
				(pMman));

	return hnd_slist;
}

void
	synapse_structure_single_linked_cleanup
		(synapse_structure_single_linked pSlist)
{
	__synapse_structure_slist_cleanup
		(synapse_structure_opaque_handle_reference
			(pSlist));
}

void
    synapse_structure_single_linked_push
        (synapse_structure_single_linked pHead, void* pData, size_t pDataSize)
{
	__synapse_structure_slist_push
		(synapse_structure_opaque_handle_reference
			(pHead), pData, pDataSize);
}

synapse_structure_single_linked_node
    synapse_structure_single_linked_pop
        (synapse_structure_single_linked pHead)
{
	synapse_structure_opaque_handle_init
		(synapse_structure_single_linked_node,
			hnd_node,
				__synapse_structure_slist_pop
					(synapse_structure_opaque_handle_reference
						(pHead)));

	return hnd_node;
}

synapse_structure_single_linked_node
    synapse_structure_single_linked_pop_until_success
        (synapse_structure_single_linked pHead)
{
	synapse_structure_opaque_handle_init
		(synapse_structure_single_linked_node,
			hnd_node, NULL);

	while 
		(!synapse_structure_opaque_handle_reference
			((hnd_node 
				= synapse_structure_single_linked_pop
						(pHead))));

	return hnd_node;
}

synapse_structure_single_linked_node
    synapse_structure_single_linked_peek
        (synapse_structure_single_linked pHead)
{
	synapse_structure_opaque_handle_init
		(synapse_structure_single_linked_node,
			hnd_peek,
				__synapse_structure_slist_peek
					(synapse_structure_opaque_handle_reference
						(pHead)));

	return
		hnd_peek;
}

void*  
    synapse_structure_single_linked_node_data
        (synapse_structure_single_linked_node pNode)
{
	return
		synapse_structure_opaque_handle_cast
			(pNode, __synapse_structure_slist_node*)
				->data_ptr;

}

size_t 
    synapse_structure_single_linked_node_size
        (synapse_structure_single_linked_node pNode)
{
	return
		synapse_structure_opaque_handle_cast
			(pNode, __synapse_structure_slist_node*)
				->data_size;
}