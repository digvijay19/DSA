#include "msort.h"
#include <stdlib.h>
#include <memory.h>

void mergeAll(void **base,  void** leftArrayBase, void** rightArrayBase, int leftLength,int rightLength, compare cmp){
    int i = 0,j = 0,temp = 0;
    while( i < leftLength && j < rightLength){
        if(cmp(leftArrayBase[i], rightArrayBase[j]) < 0){
            base[temp] = leftArrayBase[i];
            i++;
        }
        else{
            base[temp] = rightArrayBase[j];
            j++;
        }
        temp++;
    }
    while(i < leftLength){
        base[temp] = leftArrayBase[i];
        i++;temp++;
    }
    while(j < rightLength){
        base[temp] = rightArrayBase[i];
        j++;temp++;
    }
}

void mSort(void** base, int numberOfElements , compare comp){
	int centerIndex = numberOfElements/2;
    int leftLength = centerIndex;
    int rightLength = numberOfElements - centerIndex;
    int i;
    void** leftArray = calloc(leftLength, sizeof(void*));
    void** rightRight = calloc(rightLength, sizeof(void*));
    if(numberOfElements <= 1) return;
    for(i = 0; i < leftLength ;i++){
        leftArray[i] = base[i];
    }
    for(i = centerIndex; i < numberOfElements ;i++){
        rightRight[i-centerIndex] = base[i];
    }
    mSort(leftArray, leftLength, comp);
    mSort(rightRight, rightLength, comp);
    mergeAll(base, leftArray, rightRight, leftLength, rightLength, comp);
    free(leftArray);
    free(rightRight);
}