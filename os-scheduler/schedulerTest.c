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
	ASSERT(scheduler->tail == NULL);
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
	ASSERT(scheduler->tail == &one);
	ASSERT(scheduler->total == 1);
	free(scheduler);
}
void test_insert_two_processes_in_scheduler(){
	Process one = {"one",20,1,NULL};
	Process two = {"two",20,1,NULL};
	Process *oneTemp;
	Scheduler *scheduler = createScheduler(10);
	insertProcess(scheduler,&one);
	insertProcess(scheduler,&two);
	oneTemp = scheduler->head;
	ASSERT(scheduler->head == &one);
	ASSERT(scheduler->tail == &two);
	ASSERT(oneTemp == &one);
	ASSERT(oneTemp->nextProcess == &two);
	free(scheduler);
}
void test_insert_three_processes_in_scheduler(){
	Process one = {"one",20,1,NULL};
	Process two = {"two",20,1,NULL};
	Process three = {"Three",20,1,NULL};
	Process *oneTemp,*twoTemp;
	Scheduler *scheduler = createScheduler(10);
	
	insertProcess(scheduler,&one);
	insertProcess(scheduler,&two);
	insertProcess(scheduler,&three);
	
	oneTemp = scheduler->head;
	twoTemp = oneTemp->nextProcess;

	ASSERT(oneTemp == &one);
	ASSERT(twoTemp == &two);
	ASSERT(twoTemp->nextProcess == &three);
	ASSERT(scheduler->head == &one);
	ASSERT(scheduler->tail == &three);
	free(scheduler);
}
void test_execute_process_in_scheduler(){
	Process one = {"one",10,1,NULL};
	Scheduler *scheduler = createScheduler(10);
	insertProcess(scheduler,&one);
	execute(scheduler,10);
	ASSERT(one.time == 0);
	free(scheduler);
}
void test_execute_process_in_scheduler_for_half_time_than_required(){
	Process one = {"one",10,1,NULL};
	Scheduler *scheduler = createScheduler(10);
	insertProcess(scheduler,&one);
	execute(scheduler,5);
	ASSERT(one.time == 5);
	free(scheduler);
}
void test_execute__two_process_in_scheduler_when_process_is_greater_than_timeslice(){
	Process one = {"one",20,1,NULL};
	Process two = {"two",10,1,NULL};
	Scheduler *scheduler = createScheduler(10);
	insertProcess(scheduler,&one);
	insertProcess(scheduler,&two);
	execute(scheduler,20);
	ASSERT(one.time == 10);
	ASSERT(two.time == 0);
	free(scheduler);
}
void test_execute_processes_in_circular_manner(){
	Process one = {"one",20,1,NULL};
	Process two = {"two",10,1,NULL};
	Scheduler *scheduler = createScheduler(10);
	insertProcess(scheduler,&one);
	insertProcess(scheduler,&two);
	execute(scheduler,30);
	ASSERT(one.time == 0);
	ASSERT(two.time == 0);
	free(scheduler);
}