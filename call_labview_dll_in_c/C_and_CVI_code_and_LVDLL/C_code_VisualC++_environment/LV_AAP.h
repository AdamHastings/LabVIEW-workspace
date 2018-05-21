#include "extcode.h"
#pragma pack(push)
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

void __stdcall Acquire(double Y[], long len);
void __stdcall Analyze(double InputArray[], double Magnitude[], long len, 
	long len2);
void __stdcall Present(double AnalyzedDataArray[], 
	double OriginalDataArray[], long len, long len2);

long __cdecl LVDLLStatus(char *errStr, int errStrLen, void *module);

#ifdef __cplusplus
} // extern "C"
#endif

#pragma pack(pop)

