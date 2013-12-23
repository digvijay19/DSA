#include "isort.h"
#include <stdlib.h>
#include <memory.h>

void isort(void* base, int numberOfElements, int elementSize,compare comp){
	void* temp = calloc(1,elementSize);
	int i,j;
	for(i= 1; i< numberOfElements; i++){
		memcpy(temp,base+i*elementSize,elementSize);
		j = i-1;
		while(j >= 0 && (comp(temp,base+j*elementSize) < 0)){
			memcpy(base+((j+1)*elementSize),base+j*elementSize,elementSize);
			j --;
		}
		memcpy(base+(j+1)*elementSize,temp,elementSize);
	}
	free(temp);
}