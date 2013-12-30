#include "msort.h"
#include <stdlib.h>
#include <memory.h>

void mergeAll(void **base,  void** lBase, void** rBase, int leftLength,int rightLength, compare cmp){
    int i = 0,j = 0,k = 0;
    while( i < leftLength && j < rightLength){
        if(cmp(lBase[i], rBase[j]) < 0){
            base[k] = lBase[i];
            i++;
        }
        else{
            base[k] = rBase[j];
            j++;
        }
        k++;
    }
    while(i < leftLength){
        base[k] = lBase[i];
        i++;k++;
    }
    while(j < rightLength){
        base[k] = rBase[i];
        j++;k++;
    }
}

void mSort(void** base, int numberOfElements , compare comp){
	int centerIndex = numberOfElements/2;
    int leftLength = centerIndex;
    int i;
    int rightLength = numberOfElements - centerIndex;
    void** leftSide = calloc(leftLength, sizeof(void*));
    void** rightSide = calloc(rightLength, sizeof(void*));
    if(numberOfElements <= 1) return;
    for(i = 0; i < leftLength ;i++){
        leftSide[i] = base[i];
    }
    for(i = centerIndex; i < numberOfElements ;i++){
        rightSide[i-centerIndex] = base[i];
    }
    mSort(leftSide, leftLength, comp);
    mSort(rightSide, rightLength, comp);
    mergeAll(base, leftSide, rightSide, leftLength, rightLength, comp);
    free(leftSide);
    free(rightSide);
}