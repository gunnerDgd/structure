#include <structure/list/double_linked.h>

#include <structure/details/list/double_linked/dlist_init.h>
#include <structure/details/list/double_linked/dlist_manip.h>

#include <synapse/memory/interface/memory_manager.h>

synapse_structure_double_linked
	synapse_structure_double_linked_initialize
		(synapse_memory_manager* pMman)
{
	synapse_structure_double_linked ptr_dlist = 
		{ .opaque = __synapse_structure_dlist_initialize(pMman) };

	return ptr_dlist;
}

void
synapse_structure_double_linked_cleanup
	(synapse_structure_double_linked pDoubleLinked)
{
	__synapse_structure_dlist_cleanup(pDoubleLinked.opaque);
}