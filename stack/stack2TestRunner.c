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

	testStarted("test_create_stack_of_two_integers");
	setup();
		test_create_stack_of_two_integers();
	tearDown();
	testEnded();
	testStarted("test_create_stack_of_two_doubles");
	setup();
		test_create_stack_of_two_doubles();
	tearDown();
	testEnded();
	testStarted("test_create_stack_of_two_chars");
	setup();
		test_create_stack_of_two_chars();
	tearDown();
	testEnded();
	testStarted("test_create_stack_of_two_Strings");
	setup();
		test_create_stack_of_two_Strings();
	tearDown();
	testEnded();
	testStarted("test_push_integer_in_stack");
	setup();
		test_push_integer_in_stack();
	tearDown();
	testEnded();
	testStarted("test_push_String_in_stack");
	setup();
		test_push_String_in_stack();
	tearDown();
	testEnded();
	testStarted("test_stack_push_reallocates_memory_when_size_is_exceded");
	setup();
		test_stack_push_reallocates_memory_when_size_is_exceded();
	tearDown();
	testEnded();
	testStarted("test_pop_integer_from_stack");
	setup();
		test_pop_integer_from_stack();
	tearDown();
	testEnded();
	testStarted("test_underflow_of_pop");
	setup();
		test_underflow_of_pop();
	tearDown();
	testEnded();
	testStarted("test_top_of_integer_stack");
	setup();
		test_top_of_integer_stack();
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
