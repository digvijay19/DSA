#include "bsearch.h"

void* binarySearch (const void* key, const void* base,size_t length,size_t typeSize,CompareFunc* compare){
	int startIndex = 0;
	int lastIndex = length-1;
	int differnce;
	int middle;
	while(startIndex <= lastIndex){
		middle = (startIndex + lastIndex)/2;
		differnce = compare(key, base + middle * typeSize);
		if(!differnce)
			return (void*)(base + middle * typeSize);
		if(differnce > 0)
			startIndex = middle+1;
		else
			lastIndex = middle-1;
	}
	return NULL;
}