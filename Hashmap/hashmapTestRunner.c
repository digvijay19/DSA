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

	testStarted("test_put_one_element_into_hashmap");
	setup();
		test_put_one_element_into_hashmap();
	tearDown();
	testEnded();
	testStarted("test_put_two_elements_in_same_slot_of_hashMap");
	setup();
		test_put_two_elements_in_same_slot_of_hashMap();
	tearDown();
	testEnded();
	testStarted("test_put_multiple_elements_in_different_slots_of_hashMap");
	setup();
		test_put_multiple_elements_in_different_slots_of_hashMap();
	tearDown();
	testEnded();
	testStarted("test_getValue_when_element_present");
	setup();
		test_getValue_when_element_present();
	tearDown();
	testEnded();
	testStarted("test_getValue_when_element_not_present");
	setup();
		test_getValue_when_element_not_present();
	tearDown();
	testEnded();
	testStarted("test_put_updates_value_when_key_is_already_present");
	setup();
		test_put_updates_value_when_key_is_already_present();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}