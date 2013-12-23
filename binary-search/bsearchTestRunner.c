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

	testStarted("test_bsearch_for_middle_element_of_sorted_intergers");
	setup();
		test_bsearch_for_middle_element_of_sorted_intergers();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_element_not_in_middle");
	setup();
		test_bsearch_for_element_not_in_middle();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_element_in_left");
	setup();
		test_bsearch_for_element_in_left();
	tearDown();
	testEnded();
	testStarted("test_bsearch_integer_is_not_present");
	setup();
		test_bsearch_integer_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_floating_number");
	setup();
		test_bsearch_for_floating_number();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_floating_number_when_not_present");
	setup();
		test_bsearch_for_floating_number_when_not_present();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_character");
	setup();
		test_bsearch_for_character();
	tearDown();
	testEnded();
	testStarted("test_bsearch_for_character_when_not_present");
	setup();
		test_bsearch_for_character_when_not_present();
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
