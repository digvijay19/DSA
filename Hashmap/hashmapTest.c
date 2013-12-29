#include "testUtils.h"
#include "hashmap.h"
#include "privateHashmap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* one,void* two){
	return *(int*)one - *(int*)two;
}
int keyGenerator(void* key){
	return *(int*)key;
}
void test_put_into_hashmap(){
	Hashmap map = createHashmap(&compareIntegers, &keyGenerator);
	int value = 20;
	int key = 2;
	ASSERT(put(&map,&key,&value));
}