#include "testUtils.h"
#include "scheduler.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_new_process(){
	Process *process = newProcess("one", 30,1);
	ASSERT(process->priority == 1);
	ASSERT(process->time == 30);
	ASSERT(strcmp(process->name,"one") == 0);
	ASSERT(process->nextProcess == NULL);
	free(process);
}
void test_create_scheduler_with_timeslice_10_sec(){
	Scheduler *scheduler = createScheduler(10);
	ASSERT(scheduler->head == NULL);
	ASSERT(scheduler->total == 0);
	ASSERT(scheduler->timeSlice == 10);
	free(scheduler);
}
void test_insert_process_in_scheduler(){
	Process one = {"one",20,1,NULL};
	Scheduler *scheduler = createScheduler(10);
	int result;
	result = insertProcess(scheduler,&one);
	ASSERT(result == 1);
	ASSERT(scheduler->head == &one);
	ASSERT(scheduler->total == 1);
}