#include "testUtils.h"
#include "bubblesort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}
int compareFloats(void* one,void* two){
	return *(float*)one - *(float*)two;
}
int compareDoubles(void* one,void* two){
	return *(double*)one - *(double*)two;
}
int compareStrings(void* one,void* two){
	return strcmp(one,two);
}
int compareChars(void* one,void* two){
	return *(char*)one - *(char*)two;
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
void test_bubble_sort_array_of_doubles(){
    double actual[] = {2.0f,3.0f,1.0f};
    double expected[] = {1.0f,2.0f,3.0f};
    bubbleSort(actual, 3, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_doubles_best_case(){
    double actual[] = {1.0f,2.0f,3.0f};
    double expected[] = {1.0f,2.0f,3.0f};
    bubbleSort(actual, 3, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_doubles_worst_case(){
    double actual[] = {3.0f,2.0f,1.0f};
    double expected[] = {1.0f,2.0f,3.0f};
    bubbleSort(actual, 3, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_String(){
    String actual[] = {"dubeg","aniket","rajKumar"};
    String expected[] = {"aniket","dubeg","rajKumar"};
    bubbleSort(actual, 3, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_String_best_case(){
   String actual[] = {"aniket","dubeg","rajKumar"};
    String expected[] = {"aniket","dubeg","rajKumar"};
    bubbleSort(actual, 3, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_String_worst_case(){
    String actual[] = {"rajKumar","dubeg","aniket"};
    String expected[] = {"aniket","dubeg","rajKumar"};
    bubbleSort(actual, 3, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_characters(){
    char actual[] = {'b','a','c'};
    char expected[] = {'a','b','c'};
    bubbleSort(actual, 3, sizeof(char), compareChars);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_characters_best_case(){
   	char actual[] = {'a','b','c'};
    char expected[] = {'a','b','c'};
    bubbleSort(actual, 3, sizeof(char), compareChars);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
void test_bubble_sort_array_of_characters_worst_case(){
    char actual[] = {'c','b','a'};
    char expected[] = {'a','b','c'};
    bubbleSort(actual, 3, sizeof(char), compareChars);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
