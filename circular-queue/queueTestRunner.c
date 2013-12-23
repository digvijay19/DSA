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

	testStarted("test_create_integer_queue_of_length_two");
	setup();
		test_create_integer_queue_of_length_two();
	tearDown();
	testEnded();
	testStarted("test_enqueue_integer_queue");
	setup();
		test_enqueue_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_integer_queue");
	setup();
		test_dequeue_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_does_not_dequeue_empty_integer_queue");
	setup();
		test_does_not_dequeue_empty_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_does_not_enqueue_full_integer_queue");
	setup();
		test_does_not_enqueue_full_integer_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_integer_queue_in_circular_way");
	setup();
		test_enqueue_integer_queue_in_circular_way();
	tearDown();
	testEnded();
	testStarted("test_dequeue_integer_queue_in_circular_way");
	setup();
		test_dequeue_integer_queue_in_circular_way();
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
