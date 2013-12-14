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

	testStarted("test_create_queue_of_two_integers");
	setup();
		test_create_queue_of_two_integers();
	tearDown();
	testEnded();
	testStarted("test_create_queue_of_two_floats");
	setup();
		test_create_queue_of_two_floats();
	tearDown();
	testEnded();
	testStarted("test_create_queue_of_two_double");
	setup();
		test_create_queue_of_two_double();
	tearDown();
	testEnded();
	testStarted("test_create_queue_of_two_chars");
	setup();
		test_create_queue_of_two_chars();
	tearDown();
	testEnded();
	testStarted("test_create_queue_of_two_Strings");
	setup();
		test_create_queue_of_two_Strings();
	tearDown();
	testEnded();
	testStarted("test_enqueue_of_integer");
	setup();
		test_enqueue_of_integer();
	tearDown();
	testEnded();
	testStarted("test_enqueue_of_float");
	setup();
		test_enqueue_of_float();
	tearDown();
	testEnded();
	testStarted("test_enqueue_of_character");
	setup();
		test_enqueue_of_character();
	tearDown();
	testEnded();
	testStarted("test_enqueue_of_string");
	setup();
		test_enqueue_of_string();
	tearDown();
	testEnded();
	testStarted("test_when_full_do_not_enqueue");
	setup();
		test_when_full_do_not_enqueue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_of_interger_queue");
	setup();
		test_dequeue_of_interger_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_of_interger_queue_gives_dequeued_element");
	setup();
		test_dequeue_of_interger_queue_gives_dequeued_element();
	tearDown();
	testEnded();
	testStarted("test_dequeue_of_float_queue");
	setup();
		test_dequeue_of_float_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_of_character_queue");
	setup();
		test_dequeue_of_character_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_of_String_queue");
	setup();
		test_dequeue_of_String_queue();
	tearDown();
	testEnded();
	testStarted("test_dequeue_when_empty");
	setup();
		test_dequeue_when_empty();
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
