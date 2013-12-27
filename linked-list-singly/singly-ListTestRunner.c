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

	testStarted("test_insert_integer_node_in_empty_list");
	setup();
		test_insert_integer_node_in_empty_list();
	tearDown();
	testEnded();
	testStarted("test_insert_two_nodes_and_remove_them");
	setup();
		test_insert_two_nodes_and_remove_them();
	tearDown();
	testEnded();
	testStarted("test_insert_when_list_is_NULL");
	setup();
		test_insert_when_list_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_insert_at_negative_position");
	setup();
		test_insert_at_negative_position();
	tearDown();
	testEnded();
	testStarted("test_insert_when_position_not_present");
	setup();
		test_insert_when_position_not_present();
	tearDown();
	testEnded();
	testStarted("test_remove_when_list_is_empty");
	setup();
		test_remove_when_list_is_empty();
	tearDown();
	testEnded();
	testStarted("test_remove_when_list_is_NULL");
	setup();
		test_remove_when_list_is_NULL();
	tearDown();
	testEnded();
	testStarted("test_remove_psition_is_negative");
	setup();
		test_remove_psition_is_negative();
	tearDown();
	testEnded();
	testStarted("test_remove_psition_is_not_present");
	setup();
		test_remove_psition_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_getIndex_of_first_element_from_list");
	setup();
		test_getIndex_of_first_element_from_list();
	tearDown();
	testEnded();
	testStarted("test_getIndex_of_last_element_from_list");
	setup();
		test_getIndex_of_last_element_from_list();
	tearDown();
	testEnded();
	testStarted("test_getIndex_of_any_element_from_list");
	setup();
		test_getIndex_of_any_element_from_list();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
