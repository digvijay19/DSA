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

int compareFloats(void* a, void* b){
    return (*(float*)a - *(float*)b);
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
    int array[5] = {1,2,3,4,5};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareIntegers);
    ASSERT(areArrayEqual(base, expected, 5));
}
void test_merge_sort_array_of_integers_worst_case(){
    int array[5] = {1,2,3,4,5};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareIntegers);
    ASSERT(areArrayEqual(base, expected, 5));
}
void test_merge_sort_array_of_Doubles(){
    double array[5] = {1.0,2.0,3.0,4.0,5.0};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareDoubles);
    ASSERT(areArrayEqual(base, expected, 5));
}
void test_merge_sort_array_of_Doubles_worst_case(){
    double array[5] = {1.0,2.0,3.0,4.0,5.0};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareDoubles);
    ASSERT(areArrayEqual(base, expected, 5));
}
void test_merge_sort_array_of_Floats(){
    float array[5] = {1.0,2.0,3.0,4.0,5.0};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareFloats);
    ASSERT(areArrayEqual(base, expected, 5));
}
void test_merge_sort_array_of_Floats_worst_case(){
    float array[5] = {1.0,2.0,3.0,4.0,5.0};
    void* base[5] = {&array[4],&array[3],&array[2],&array[1],&array[0]};
    void* expected[5] = {&array[0],&array[1],&array[2],&array[3],&array[4]};
    mSort(base, 5, compareFloats);
    ASSERT(areArrayEqual(base, expected, 5));
}