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

	testStarted("test_push_element_into_stack");
	setup();
		test_push_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_multiple_elements_into_stack");
	setup();
		test_push_multiple_elements_into_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_stack");
	setup();
		test_pop_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_when_stack_is_empty");
	setup();
		test_pop_when_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_top_when_one_element_present");
	setup();
		test_top_when_one_element_present();
	tearDown();
	testEnded();
	testStarted("test_top_when_multiple_elements_present");
	setup();
		test_top_when_multiple_elements_present();
	tearDown();
	testEnded();
	testStarted("test_top_when_stack_is_empty");
	setup();
		test_top_when_stack_is_empty();
	tearDown();
	testEnded();
	testStarted("test_top_when_stack_is_null");
	setup();
		test_top_when_stack_is_null();
	tearDown();
	testEnded();
	testStarted("test_push_when_stack_is_null");
	setup();
		test_push_when_stack_is_null();
	tearDown();
	testEnded();
	testStarted("test_pop_when_stack_is_null");
	setup();
		test_pop_when_stack_is_null();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_when_stack_is_null");
	setup();
		test_isEmpty_when_stack_is_null();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_when_not_empty");
	setup();
		test_isEmpty_when_not_empty();
	tearDown();
	testEnded();
	testStarted("test_isEmpty_when_empty");
	setup();
		test_isEmpty_when_empty();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
