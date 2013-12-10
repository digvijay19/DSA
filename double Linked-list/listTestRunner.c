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
	testStarted("test_insert_element_to_a_list_when_one_element_present");
	setup();
		test_insert_element_to_a_list_when_one_element_present();
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
	testStarted("test_insert_elements_of_different_data_types");
	setup();
		test_insert_elements_of_different_data_types();
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
