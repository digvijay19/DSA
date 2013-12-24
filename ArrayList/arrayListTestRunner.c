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

	testStarted("test_insert_element");
	setup();
		test_insert_element();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_elements");
	setup();
		test_insert_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_interns_grows_beyond_capacity");
	setup();
		test_interns_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_index_beyond_length");
	setup();
		test_should_not_insert_at_index_beyond_length();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_negative_index");
	setup();
		test_should_not_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_insert_at_middle_should_shift_the_elements");
	setup();
		test_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_when_list_is_null");
	setup();
		test_should_not_insert_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_add_element_when_list_is_empty");
	setup();
		test_add_element_when_list_is_empty();
	tearDown();
	testEnded();
	testStarted("test_add_multiple_elements");
	setup();
		test_add_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_add_list_grows_beyond_capacity");
	setup();
		test_add_list_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_should_not_add_when_list_is_null");
	setup();
		test_should_not_add_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_remove_element");
	setup();
		test_remove_element();
	tearDown();
	testEnded();
	testStarted("test_remove_element_when_multiple_elements_present");
	setup();
		test_remove_element_when_multiple_elements_present();
	tearDown();
	testEnded();
	testStarted("test_remove_element_when_index_element_not_present");
	setup();
		test_remove_element_when_index_element_not_present();
	tearDown();
	testEnded();
	testStarted("test_remove_element_when_index_is_negative");
	setup();
		test_remove_element_when_index_is_negative();
	tearDown();
	testEnded();
	testStarted("test_search_integer_from_list");
	setup();
		test_search_integer_from_list();
	tearDown();
	testEnded();
	testStarted("test_search_when_element_not_present");
	setup();
		test_search_when_element_not_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
