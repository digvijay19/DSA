#include "testUtils.h"
#include "bubblesort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}
void test_bubble_sort_array_of_integers(){
    int actual[] = {2,3,1};
    int expected[] = {1,2,3};
    bubbleSort(actual, 3, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_integers_best_case(){
    int actual[] = {1,2,3};
    int expected[] = {1,2,3};
    bubbleSort(actual, 3, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}