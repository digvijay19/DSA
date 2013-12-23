#include "testUtils.h"
#include "bsearch.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers (const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}
int comparefloats (const void* a, const void* b){
	return (*(float*)a - *(float*)b);
}
int compareCharacters(const void* a,const void* b){
	return (*(char*)a - *(char*)b);
}

void test_bsearch_for_middle_element_of_sorted_intergers(){
	int* result ;
	int key = 30;
	int numbers[] = {10,20,30,40,50};
	result = (int*)binarySearch(&key, numbers, 5, sizeof(int), compareIntegers);
	ASSERT(*result == 30 && result == &numbers[2]);
}
void test_bsearch_for_element_not_in_middle(){
	int* result ;
	int key = 40;
	int numbers[] = {10,20,30,40,50};
	result = (int*)binarySearch(&key, numbers, 5, sizeof(int), compareIntegers);
	ASSERT(*result == 40);
}
void test_bsearch_for_element_in_left(){
	int* result ;
	int key = 20;
	int numbers[] = {10,20,30,40,50};
	result = (int*)binarySearch(&key, numbers, 5, sizeof(int), compareIntegers);
	ASSERT(*result == 20);
}
void test_bsearch_integer_is_not_present(){
	int* result ;
	int key = 210;
	int numbers[] = {10,20,30,40,50};
	result = binarySearch(&key, numbers, 5, sizeof(int), compareIntegers);
	ASSERT(result == NULL);
}
void test_bsearch_for_floating_number(){
	void* result ;
	float key = 30.1;
	float numbers[] = {10.1,20.1,30.1,40.1,50.1};
	result = binarySearch(&key, numbers, 5, sizeof(float), comparefloats);
	ASSERT(result == &numbers[2]);
}
void test_bsearch_for_floating_number_when_not_present(){
	void* result ;
	float key = 30.1;
	float numbers[] = {10.1,20.1,20.9,40.1,50.1};
	result = binarySearch(&key, numbers, 5, sizeof(float), comparefloats);
	ASSERT(result == NULL);
}
void test_bsearch_for_character(){
	void* result ;
	char character = 'b';
	char characters[] = {'a','b','c','d','e'};
	result = binarySearch(&character, characters, 5, sizeof(char), compareCharacters);
	ASSERT(result == &characters[1]);
}
void test_bsearch_for_character_when_not_present(){
	void* result ;
	char character = 'f';
	char characters[] = {'a','b','c','d','e'};
	result = binarySearch(&character, characters, 5, sizeof(char), compareCharacters);
	ASSERT(result == NULL);
}