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
	Node* node = createNode(&element);
	ASSERT(1 == insert(list, node, 0));	
	ASSERT(list->length == 1);
	ASSERT(1 == remove(list, 0));	
	ASSERT(list->length == 0);
}
void test_insert_two_nodes_and_remove_them(){
	int element = 10;
	Node* nodeOne = createNode(&element);
	Node* nodeTwo = createNode(&element);
	ASSERT(1 == insert(list, nodeOne, 0));
	ASSERT(1 == insert(list, nodeTwo, 1));
	ASSERT(list->length == 2);
	ASSERT(1 == remove(list, 1));	
	ASSERT(1 == remove(list, 0));	
	ASSERT(list->length == 0);
}