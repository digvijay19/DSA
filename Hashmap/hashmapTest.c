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
void test_put_one_element_into_hashmap(){
	int value = 20;
	int key = 2;
	ASSERT(put(&map,&key,&value) == SUCCESS);
	ASSERT(getValue(&map,&key) == &value);
}
void test_put_two_elements_in_same_slot_of_hashMap(){
	int values[] = {100,200};
	int keys[] = {11,21};
	ASSERT(put(&map,&keys[0],&values[0]) == SUCCESS);
	ASSERT(put(&map,&keys[1],&values[1]) == SUCCESS);
	ASSERT(getValue(&map,&keys[0]) == &values[0]);
	ASSERT(getValue(&map,&keys[1]) == &values[1]);
}
void test_put_multiple_elements_in_different_slots_of_hashMap(){
	int values[] = {100,200,300,400};
	int keys[] = {11,12,13,14};
	ASSERT(put(&map,&keys[0],&values[0]) == SUCCESS);
	ASSERT(put(&map,&keys[1],&values[1]) == SUCCESS);
	ASSERT(put(&map,&keys[2],&values[2]) == SUCCESS);
	ASSERT(put(&map,&keys[3],&values[3]) == SUCCESS);
	ASSERT(getValue(&map,&keys[0]) == &values[0]);
	ASSERT(getValue(&map,&keys[1]) == &values[1]);
	ASSERT(getValue(&map,&keys[2]) == &values[2]);
	ASSERT(getValue(&map,&keys[3]) == &values[3]);
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

void test_put_updates_value_when_key_is_already_present(){
	int values[] = {100,200};
	int key = 11;
	ASSERT(put(&map,&key,&values[0]) == SUCCESS);
	ASSERT(put(&map,&key,&values[1]) == SUCCESS);
	ASSERT(getValue(&map,&key) == &values[1]);
}
void test_remove_from_hashMap(){
	int value = 20;
	int key = 2;
	ASSERT(put(&map,&key,&value) == SUCCESS);
	ASSERT(removeFromHashMap(&map,&key) == SUCCESS);
	ASSERT(getValue(&map,&key) == NULL);
}