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
	testStarted("test_create_stack_of_two_floats");
	setup();
		test_create_stack_of_two_floats();
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
	testStarted("test_overflow_of_stack_when_pushed");
	setup();
		test_overflow_of_stack_when_pushed();
	tearDown();
	testEnded();
	testStarted("test_push_float_in_stack");
	setup();
		test_push_float_in_stack();
	tearDown();
	testEnded();
	testStarted("test_push_float_in_stack_two_times");
	setup();
		test_push_float_in_stack_two_times();
	tearDown();
	testEnded();
	testStarted("test_push_double_in_stack");
	setup();
		test_push_double_in_stack();
	tearDown();
	testEnded();
	testStarted("test_push_char_in_stack");
	setup();
		test_push_char_in_stack();
	tearDown();
	testEnded();
	testStarted("test_push_String_in_stack");
	setup();
		test_push_String_in_stack();
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
	testStarted("test_pop_float_from_stack");
	setup();
		test_pop_float_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_double_from_stack");
	setup();
		test_pop_double_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_char_from_stack");
	setup();
		test_pop_char_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_String_from_stack");
	setup();
		test_pop_String_from_stack();
	tearDown();
	testEnded();
	testStarted("test_top_of_integer_stack");
	setup();
		test_top_of_integer_stack();
	tearDown();
	testEnded();
	testStarted("test_top_of_float_stack");
	setup();
		test_top_of_float_stack();
	tearDown();
	testEnded();
	testStarted("test_top_of_double_stack");
	setup();
		test_top_of_double_stack();
	tearDown();
	testEnded();
	testStarted("test_top_of_char_stack");
	setup();
		test_top_of_char_stack();
	tearDown();
	testEnded();
	testStarted("test_top_of_String_stack");
	setup();
		test_top_of_String_stack();
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
