#ifdef SYNAPSE_BUILD_ENVIORMENT_GCC
#define __synapse_structure_slist_cmpxchg(pPtrDest, pValueExpected, pValueDesired)\
    __atomic_compare_exchange_n\
		(pPtrDest, &pValueExpected, pValueDesired,\
			false, __ATOMIC_RELEASE, __ATOMIC_RELAXED)
#elif SYNAPSE_BUILD_ENVIRONMENT_MSVC
#define __synapse_structure_slist_cmpxchg(pPtrDest, pValueExpected, pValueDesired)\
    (InterlockedCompareExchange64\
		(pPtrDest, pValueDesired, pValueExpected)\
			!= pValueExpected)
#endif