#ifdef synapse_structure_export_mode
#define synapse_structure_dll _declspec(dllexport)
#else
#define synapse_structure_dll _declspec(dllimport)
#endif