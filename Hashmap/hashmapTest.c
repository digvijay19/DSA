#include "testUtils.h"
#include "hashmap.h"
#include "privateHashmap.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;
const int FAIL = 0;

int compareKeys(void* one,void* two){
	return *(int*)one - *(int*)two;
}
int keyGenerator(void* key){
	return *(int*)key;
}
Hashmap map;
void setup(){
	map = createHashmap(&compareKeys, &keyGenerator);
}
void test_put_one_into_hashmap(){
	int value = 20;
	int key = 2;
	ASSERT(put(&map,&key,&value) == SUCCESS);
	ASSERT(getValue(&map,&key) == &value);
}
void test_getValue_when_element_present(){
	int value = 10;
	int key = 1;
	put(&map,&key,&value);
	ASSERT(getValue(&map,&key) == &value);
}
void test_getValue_when_element_not_present(){
	int value = 100;
	int key = 11;
	int keyToSearch = 1;
	put(&map,&key,&value);
	ASSERT(getValue(&map,&keyToSearch) == NULL);
}