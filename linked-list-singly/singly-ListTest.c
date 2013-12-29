#include "testUtils.h"
#include "singly-List.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
sList *list;
void setup(){
	list = createList();
}
void tearDown(){
	disposeList(list);
}
void test_insert_integer_node_in_empty_list(){
	int element = 10;
	ASSERT(1 == insertInList(list, &element, 0));	
	ASSERT(list->length == 1);
	ASSERT(1 == removeFromList(list, 0));	
	ASSERT(list->length == 0);
}
void test_insert_two_nodes_and_remove_them(){
	int element = 10;
	ASSERT(1 == insertInList(list, &element, 0));
	ASSERT(1 == insertInList(list, &element, 1));
	ASSERT(list->length == 2);
	ASSERT(1 == removeFromList(list, 1));	
	ASSERT(1 == removeFromList(list, 0));	
	ASSERT(list->length == 0);
}
void test_insert_when_list_is_NULL(){
	int element = 10;
	ASSERT(0 == insertInList(NULL, &element, 0));
}
void test_insert_at_negative_position(){
	int element = 10;
	ASSERT(0 == insertInList(list, &element, -1));
}
void test_insert_when_position_not_present(){
	int element = 10;
	ASSERT(0 == insertInList(list, &element, 1));
}
void test_remove_when_list_is_empty(){
	ASSERT(0 == removeFromList(list, 0));	
	ASSERT(list->length == 0);
}
void test_remove_when_list_is_NULL(){
	ASSERT(0 == removeFromList(NULL, 1));	
}
void test_remove_psition_is_negative(){
	ASSERT(0 == removeFromList(list, -1));	
}
void test_remove_psition_is_not_present(){
	int element = 10;
	ASSERT(1 == insertInList(list, &element, 0));
	ASSERT(1 == insertInList(list, &element, 0));
	ASSERT(0 == removeFromList(list, 2));
}
int compareInts(void *element,void *toSearch){
	return *(int*)element - *(int*)toSearch;
}
void test_getIndex_of_first_element_from_list(){
	int numbers[] = {1,2,3};
	int toSearch = 1;
	insertInList(list, &numbers[0], 0);
	ASSERT(0 == getIndexFromList(list, &toSearch, &compareInts));
}
void test_getIndex_of_last_element_from_list(){
	int numbers[] = {1,2,3};
	int toSearch = 3;
	insertInList(list, &numbers[0], 0);
	insertInList(list, &numbers[1], 1);
	insertInList(list, &numbers[2], 2);
	ASSERT(2 == getIndexFromList(list, &toSearch, &compareInts));
}
void test_getIndex_of_any_element_from_list(){
	int numbers[] = {1,2,3,4};
	int toSearch = 2;
	insertInList(list, &numbers[0], 0);
	insertInList(list, &numbers[1], 1);
	insertInList(list, &numbers[2], 2);
	insertInList(list, &numbers[3], 3);
	ASSERT(1 == getIndexFromList(list, &toSearch, &compareInts));
}