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

	testStarted("test_bubble_sort_array_of_integers");
	setup();
		test_bubble_sort_array_of_integers();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_integers_best_case");
	setup();
		test_bubble_sort_array_of_integers_best_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_integers_worst_case");
	setup();
		test_bubble_sort_array_of_integers_worst_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_floats");
	setup();
		test_bubble_sort_array_of_floats();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_floats_best_case");
	setup();
		test_bubble_sort_array_of_floats_best_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_floats_worst_case");
	setup();
		test_bubble_sort_array_of_floats_worst_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_doubles");
	setup();
		test_bubble_sort_array_of_doubles();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_doubles_best_case");
	setup();
		test_bubble_sort_array_of_doubles_best_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_doubles_worst_case");
	setup();
		test_bubble_sort_array_of_doubles_worst_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_String");
	setup();
		test_bubble_sort_array_of_String();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_String_best_case");
	setup();
		test_bubble_sort_array_of_String_best_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_String_worst_case");
	setup();
		test_bubble_sort_array_of_String_worst_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_characters");
	setup();
		test_bubble_sort_array_of_characters();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_characters_best_case");
	setup();
		test_bubble_sort_array_of_characters_best_case();
	tearDown();
	testEnded();
	testStarted("test_bubble_sort_array_of_characters_worst_case");
	setup();
		test_bubble_sort_array_of_characters_worst_case();
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
