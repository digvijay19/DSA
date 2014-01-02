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

	testStarted("test_insert_root_node_in_BST");
	setup();
		test_insert_root_node_in_BST();
	tearDown();
	testEnded();
	testStarted("test_insert_left_Of_root");
	setup();
		test_insert_left_Of_root();
	tearDown();
	testEnded();
	testStarted("test_insert_right_Of_root");
	setup();
		test_insert_right_Of_root();
	tearDown();
	testEnded();
	testStarted("test_insert_left_and_right_to_root");
	setup();
		test_insert_left_and_right_to_root();
	tearDown();
	testEnded();
	testStarted("test_insert_left_at_level_2");
	setup();
		test_insert_left_at_level_2();
	tearDown();
	testEnded();
	testStarted("test_search_data_in_root_node");
	setup();
		test_search_data_in_root_node();
	tearDown();
	testEnded();
	testStarted("test_search_data_in_left_node");
	setup();
		test_search_data_in_left_node();
	tearDown();
	testEnded();
	testStarted("test_search_data_in_right_node");
	setup();
		test_search_data_in_right_node();
	tearDown();
	testEnded();
	testStarted("test_search_data_when_data_is_not_present");
	setup();
		test_search_data_when_data_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_do_not_insert_duplicate_data");
	setup();
		test_do_not_insert_duplicate_data();
	tearDown();
	testEnded();
	testStarted("test_get_children_of_root");
	setup();
		test_get_children_of_root();
	tearDown();
	testEnded();
	testStarted("test_get_children_of_root_when_children_not_present");
	setup();
		test_get_children_of_root_when_children_not_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
