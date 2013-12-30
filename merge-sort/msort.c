#include "msort.h"
#include <stdlib.h>
#include <memory.h>

void merge(void **destination,  void** leftBase, void** rightBase, size_t leftLength,size_t rightLength, compare comp){
    int i = 0,j = 0,k = 0;
    for(; i < leftLength && j < rightLength;){
        if(comp(leftBase[i], rightBase[j]) < 0){
            destination[k] = leftBase[i];
            i++;
        }
        else{
            destination[k] = rightBase[j];
            j++;
        }
        k++;
    }
    while(i < leftLength){
        destination[k] = leftBase[i];
        i++;k++;
    }
    while(j < rightLength){
        destination[k] = rightBase[i];
        j++;k++;
    }
}

void mSort(void** base, int numberOfElements , compare comp){
	int mid = numberOfElements/2;
    int leftLength = mid;
    int i;
    int rightLength = numberOfElements - mid;
    void** leftSide = calloc(leftLength, sizeof(void*));
    void** rightSide = calloc(rightLength, sizeof(void*));
    for(i = 0; i < leftLength ;i++){
            leftSide[i] = base[i];
    }
    for(i = mid; i < numberOfElements ;i++){
            rightSide[i-mid] = base[i];
    }
    mSort(leftSide, leftLength, comp);
    mSort(rightSide, rightLength, comp);
    merge(base, leftSide, rightSide, leftLength, rightLength, comp);
    free(leftSide);
    free(rightSide);
}