#include "testUtils.h"
#include "msort.h"
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}

void test_merge_sort_array_of_integers(){
    int actual[] = {3,1,2,4};
    void* base[] = {&actual[1],&actual[2],&actual[0],&actual[3]};
    void* expected[] = {&actual[0],&actual[1],&actual[2],&actual[4]};
    mSort(&base[0], 3, compareIntegers);
    ASSERT(0 == memcmp(expected, base, sizeof(expected)));
}