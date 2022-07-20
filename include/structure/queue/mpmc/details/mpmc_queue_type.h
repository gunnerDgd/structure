#include <stdint.h>
#include <stddef.h>

typedef struct
    __synapse_structure_mpmc_queue_node
{
    volatile void*
        ptr_mpmc_data;
    volatile
        struct __synapse_structure_mpmc_queue_node*
            ptr_mpmc_next;
} __synapse_structure_mpmc_queue_node;

typedef struct
    __synapse_structure_mpmc_queue
{
    __synapse_structure_mpmc_queue_node*
        ptr_mpmc_node;
    volatile
        __synapse_structure_mpmc_queue_node
            *ptr_mpmc_rdptr,
            *ptr_mpmc_wrptr;
} __synapse_structure_mpmc_queue;