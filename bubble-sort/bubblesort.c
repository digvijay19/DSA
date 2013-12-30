#include "bubblesort.h"
#include <stdlib.h>
#include <memory.h>

void bubbleSort(void* base, int numberOfElements, int elementSize , compare comp){
	void* temp = calloc(1,elementSize);
	void* first;
	void* second;
	int i,j;
	for(i=1; i<numberOfElements; i++){
		for(j=0; j<numberOfElements-i; j++){

			first = base + j * elementSize;
			second = base + (j+1) * elementSize;
			
			if(comp(first,second) > 0){
				memcpy(temp,first,elementSize);
				memcpy(first,second,elementSize);
				memcpy(second,temp,elementSize);
			}
		}
	}
	free(temp);
}