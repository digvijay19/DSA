#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_insert_root_node");
	setup();
		test_insert_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_node_under_root_node");
	setup();
		test_insert_node_under_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_node_under_child_node");
	setup();
		test_insert_node_under_child_node();
	tearDown();
	testEnded();
	testStarted("test_insert_node_under_second_child_node");
	setup();
		test_insert_node_under_second_child_node();
	tearDown();
	testEnded();
	testStarted("test_insert_when_tree_is_NULL");
	setup();
		test_insert_when_tree_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_insert_when_data_to_insert_is_NULL");
	setup();
		test_insert_when_data_to_insert_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_do_not_insert_when_data_is_already_present");
	setup();
		test_do_not_insert_when_data_is_already_present();
	tearDown();
	testEnded();
	testStarted("test_search_rootNode_in_tree");
	setup();
		test_search_rootNode_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_child_node_in_tree");
	setup();
		test_search_child_node_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_when_element_is_not_present");
	setup();
		test_search_when_element_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_search_when_tree_is_NULL");
	setup();
		test_search_when_tree_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_search_when_element_to_search_is_NULL");
	setup();
		test_search_when_element_to_search_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_remove_Node_from_tree");
	setup();
		test_remove_Node_from_tree();
	tearDown();
	testEnded();
	testStarted("test_remove_when_not_present");
	setup();
		test_remove_when_not_present();
	tearDown();
	testEnded();
	testStarted("test_do_not_remove_when_children_are_present");
	setup();
		test_do_not_remove_when_children_are_present();
	tearDown();
	testEnded();
	testStarted("test_remove_when_tree_is_NULL");
	setup();
		test_remove_when_tree_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_remove_when_data_is_NULL");
	setup();
		test_remove_when_data_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_dispose_of_tree");
	setup();
		test_dispose_of_tree();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
