#include <stddef.h>
#include <stdint.h>

#define synapse_structure_opaque_handle_declare(pName)\
    typedef struct pName\
    {\
        void* opaque;\
    } pName;

#define synapse_structure_opaque_handle_init(pObject, pName, pValue)\
    pObject pName = { .opaque = pValue };

#define synapse_structure_opaque_handle_reference(pObject)\
    (pObject.opaque)

#define synapse_structure_opaque_handle_cast(pObject, pType)\
    ((pType)(pObject.opaque))