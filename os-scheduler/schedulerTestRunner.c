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

	testStarted("test_create_new_process");
	setup();
		test_create_new_process();
	tearDown();
	testEnded();
	testStarted("test_create_scheduler_with_timeslice_10_sec");
	setup();
		test_create_scheduler_with_timeslice_10_sec();
	tearDown();
	testEnded();
	testStarted("test_insert_process_in_scheduler");
	setup();
		test_insert_process_in_scheduler();
	tearDown();
	testEnded();
	testStarted("test_insert_two_processes_in_scheduler");
	setup();
		test_insert_two_processes_in_scheduler();
	tearDown();
	testEnded();
	testStarted("test_insert_three_processes_in_scheduler");
	setup();
		test_insert_three_processes_in_scheduler();
	tearDown();
	testEnded();
	testStarted("test_execute_process_in_scheduler");
	setup();
		test_execute_process_in_scheduler();
	tearDown();
	testEnded();
	testStarted("test_execute_process_in_scheduler_for_half_time_than_required");
	setup();
		test_execute_process_in_scheduler_for_half_time_than_required();
	tearDown();
	testEnded();
	testStarted("test_execute__two_process_in_scheduler_when_process_is_greater_than_timeslice");
	setup();
		test_execute__two_process_in_scheduler_when_process_is_greater_than_timeslice();
	tearDown();
	testEnded();
	testStarted("test_execute_processes_in_circular_manner");
	setup();
		test_execute_processes_in_circular_manner();
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
