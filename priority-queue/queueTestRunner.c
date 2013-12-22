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

	testStarted("test_create_new_empty_priority_queue");
	setup();
		test_create_new_empty_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_create_new_node_with_data_priority_next_elementAddress");
	setup();
		test_create_new_node_with_data_priority_next_elementAddress();
	tearDown();
	testEnded();
	testStarted("test_create_new_node_floating_data");
	setup();
		test_create_new_node_floating_data();
	tearDown();
	testEnded();
	testStarted("test_create_new_node_double_data");
	setup();
		test_create_new_node_double_data();
	tearDown();
	testEnded();
	testStarted("test_create_new_node_character_data");
	setup();
		test_create_new_node_character_data();
	tearDown();
	testEnded();
	testStarted("test_create_new_node_String_data");
	setup();
		test_create_new_node_String_data();
	tearDown();
	testEnded();
	testStarted("test_enqueue_in_empty_priority_queue");
	setup();
		test_enqueue_in_empty_priority_queue();
	tearDown();
	testEnded();
	testStarted("test_enqueue_two_elements");
	setup();
		test_enqueue_two_elements();
	tearDown();
	testEnded();
	testStarted("test_enqueue_three_elements_with_different_priorities");
	setup();
		test_enqueue_three_elements_with_different_priorities();
	tearDown();
	testEnded();
	testStarted("test_enqueue_four_elements_with_different_priorities");
	setup();
		test_enqueue_four_elements_with_different_priorities();
	tearDown();
	testEnded();
	testStarted("test_enqueue_next_element_with_highest_priority");
	setup();
		test_enqueue_next_element_with_highest_priority();
	tearDown();
	testEnded();
	testStarted("test_dequeue_from_queue_of_two_elements");
	setup();
		test_dequeue_from_queue_of_two_elements();
	tearDown();
	testEnded();
	testStarted("test_dequeue_from_empty_queue");
	setup();
		test_dequeue_from_empty_queue();
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
