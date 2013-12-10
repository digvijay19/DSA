#include <stdlib.h>

typedef char String[256];
typedef int CompareFunc (const void* a,const void* b);

void* binarySearch (const void* key, const void* base,
	size_t length,size_t typeSize,CompareFunc* compare);