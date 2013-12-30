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

	testStarted("test_merge_sort_array_of_integers");
	setup();
		test_merge_sort_array_of_integers();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_array_of_integers_worst_case");
	setup();
		test_merge_sort_array_of_integers_worst_case();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_array_of_Doubles");
	setup();
		test_merge_sort_array_of_Doubles();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_array_of_Doubles_worst_case");
	setup();
		test_merge_sort_array_of_Doubles_worst_case();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_array_of_Floats");
	setup();
		test_merge_sort_array_of_Floats();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_array_of_Floats_worst_case");
	setup();
		test_merge_sort_array_of_Floats_worst_case();
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
