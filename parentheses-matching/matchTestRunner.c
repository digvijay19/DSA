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

	testStarted("test_length_of_braces_should_be_even");
	setup();
		test_length_of_braces_should_be_even();
	tearDown();
	testEnded();
	testStarted("test_odd_number_of_braces");
	setup();
		test_odd_number_of_braces();
	tearDown();
	testEnded();
	testStarted("test_incorrect_order");
	setup();
		test_incorrect_order();
	tearDown();
	testEnded();
	testStarted("test_correct_order_of_two_type_of_braces");
	setup();
		test_correct_order_of_two_type_of_braces();
	tearDown();
	testEnded();
	testStarted("test_correct_order_of_multiple_braces");
	setup();
		test_correct_order_of_multiple_braces();
	tearDown();
	testEnded();
	testStarted("test_correct_order_of_multiple_braces_with_characters");
	setup();
		test_correct_order_of_multiple_braces_with_characters();
	tearDown();
	testEnded();
	testStarted("test_incorrect_order_starting_with_closing_paranthesis");
	setup();
		test_incorrect_order_starting_with_closing_paranthesis();
	tearDown();
	testEnded();
	testStarted("test_incorrect_order_with_characters");
	setup();
		test_incorrect_order_with_characters();
	tearDown();
	testEnded();
	testStarted("test_correct_order_with_all_types_of_braces");
	setup();
		test_correct_order_with_all_types_of_braces();
	tearDown();
	testEnded();
	testStarted("test_correct_order_with_all_braces_included_in_each_other");
	setup();
		test_correct_order_with_all_braces_included_in_each_other();
	tearDown();
	testEnded();
	testStarted("test_correct_order_for_complex_code");
	setup();
		test_correct_order_for_complex_code();
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
