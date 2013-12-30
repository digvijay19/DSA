#include "testUtils.h"
#include "msort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}

int compareDoubles(void* a, void* b){
    return (*(double*)a - *(double*)b);
}

int areArrayEqual(void** a,void** b, int length){
    int i=0;
    while(i<length && (a[i] != b[i])){
        return 0;
    	i++;
    }
    return 1;
}

void test_merge_sort_array_of_integers(){
    int array[5] = {5,10,12,20,25};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareIntegers);
    ASSERT(areArrayEqual(base, expected, 5));
}
