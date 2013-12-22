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

	testStarted("test_create_of_node");
	setup();
		test_create_of_node();
	tearDown();
	testEnded();
	testStarted("test_create_double_linked_list");
	setup();
		test_create_double_linked_list();
	tearDown();
	testEnded();
	testStarted("test_insert_element_to_empty_list");
	setup();
		test_insert_element_to_empty_list();
	tearDown();
	testEnded();
	testStarted("test_insert_three_elements_and_check_the_next_of_each");
	setup();
		test_insert_three_elements_and_check_the_next_of_each();
	tearDown();
	testEnded();
	testStarted("test_insert_elements_and_check_data_of_each");
	setup();
		test_insert_elements_and_check_data_of_each();
	tearDown();
	testEnded();
	testStarted("test_insert_elements_of_different_data_types");
	setup();
		test_insert_elements_of_different_data_types();
	tearDown();
	testEnded();
	testStarted("test_insert_element_gives_true_when_inerted");
	setup();
		test_insert_element_gives_true_when_inerted();
	tearDown();
	testEnded();
	testStarted("test_insert_element_gives_false_when_not_succesfull");
	setup();
		test_insert_element_gives_false_when_not_succesfull();
	tearDown();
	testEnded();
	testStarted("test_delete_2nd_element");
	setup();
		test_delete_2nd_element();
	tearDown();
	testEnded();
	testStarted("test_delete_when_index_not_present");
	setup();
		test_delete_when_index_not_present();
	tearDown();
	testEnded();
	testStarted("test_delete_when_list_is_empty");
	setup();
		test_delete_when_list_is_empty();
	tearDown();
	testEnded();
	testStarted("test_delete_when_index_passed_is_negative");
	setup();
		test_delete_when_index_passed_is_negative();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
