#include "testUtils.h"
#include "bubblesort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

float compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}
float compareFloats(void* one,void* two){
	return *(float*)one - *(float*)two;
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
void test_bubble_sort_array_of_integers_worst_case(){
    int actual[] = {3,2,1};
    int expected[] = {1,2,3};
    bubbleSort(actual, 3, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_floats(){
    float actual[] = {2.0,3.0,1.0};
    float expected[] = {1.0,2.0,3.0};
    bubbleSort(actual, 3, sizeof(float), compareFloats);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_floats_best_case(){
    float actual[] = {1.0,2.0,3.0};
    float expected[] = {1.0,2.0,3.0};
    bubbleSort(actual, 3, sizeof(float), compareFloats);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_floats_worst_case(){
    float actual[] = {3.0,2.0,1.0};
    float expected[] = {1.0,2.0,3.0};
    bubbleSort(actual, 3, sizeof(float), compareFloats);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}