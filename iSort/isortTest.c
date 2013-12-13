#include "testUtils.h"
#include "isort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareIntegers(void* a,void* b){
	return (*(int*)a - *(int*)b);
}
int isArrayEqual(void* numbers,void* expected,int lenght,int typeSize){
	return 0 == memcmp(expected,numbers,lenght*typeSize);
}
void test_isort_worst_case_for_5_integers(){
	int numbers[] = {5,4,3,2,1};
	int expected[] = {1,2,3,4,5};
	int i;
	isort( numbers,5,sizeof(int),compareIntegers);
	
	ASSERT(isArrayEqual(numbers,expected,5,4) != 0);
}
