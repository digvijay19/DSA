#include "testUtils.h"
#include "singly-List.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
sList *list;
void setup(){
	list = createList();
}
void tearDown(){
	free(list);
}
void test_insert_integer_node_in_empty_list(){
	int element = 10;
	ASSERT(1 == insert(list, &element, 0));	
	ASSERT(list->length == 1);
	ASSERT(1 == remove(list, 0));	
	ASSERT(list->length == 0);
}
void test_insert_two_nodes_and_remove_them(){
	int element = 10;
	ASSERT(1 == insert(list, &element, 0));
	ASSERT(1 == insert(list, &element, 1));
	ASSERT(list->length == 2);
	ASSERT(1 == remove(list, 1));	
	ASSERT(1 == remove(list, 0));	
	ASSERT(list->length == 0);
}
void test_insert_when_list_is_NULL(){
	int element = 10;
	ASSERT(0 == insert(NULL, &element, 0));
}
void test_insert_at_negative_position(){
	int element = 10;
	ASSERT(0 == insert(list, &element, -1));
}
void test_insert_when_position_not_present(){
	int element = 10;
	ASSERT(0 == insert(list, &element, 1));
}
void test_remove_when_list_is_empty(){
	ASSERT(0 == remove(list, 0));	
	ASSERT(list->length == 0);
}
void test_remove_when_list_is_NULL(){
	ASSERT(0 == remove(NULL, 1));	
}
void test_remove_psition_is_negative(){
	ASSERT(0 == remove(list, -1));	
}
void test_remove_psition_is_not_present(){
	int element = 10;
	ASSERT(1 == insert(list, &element, 0));
	ASSERT(1 == insert(list, &element, 0));
	ASSERT(0 == remove(list, 2));	
}
