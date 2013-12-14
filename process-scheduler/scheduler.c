#include "scheduler.h"
#include <stdlib.h>
#include <string.h>


Process* newProcess(String name,int time,int priority){
	Process *process = calloc(1,sizeof(Process));
	memcpy(process->name,name,sizeof(String));
	process->time = time;
	process->priority = priority;
	process->nextProcess = NULL;
	return process;
}
Scheduler* createScheduler(int timeSlice){
	Scheduler *scheduler = calloc(1, sizeof(Scheduler));
	scheduler->head = NULL;
	scheduler->tail = NULL;
	scheduler->total = 0;
	scheduler->timeSlice = timeSlice;
	return scheduler;
}
int insertProcess(Scheduler* scheduler,Process* process){
	Process *first = scheduler->head;
	Process *last;
	int i;
	if(scheduler->head == NULL && scheduler->tail == NULL){
		scheduler->head = process;
		scheduler->tail = process;
		scheduler->total++;
		return 1;
	}
	last = scheduler->tail;
	last->nextProcess = process;
	scheduler->tail = process;
	scheduler->total++;
	return 1;
}
void execute(Scheduler* scheduler,int availableTime){
	Process* process = scheduler->head;
	int i,temp=0;
	for(i=1;i<=availableTime;i++){
		if(process->time > 0)
			process->time--;
		temp = temp+1;
		if(temp == 10){
			if(process->nextProcess == NULL)
				process = scheduler->head;
			else
				process =process->nextProcess;
			temp = 0;
		}
	}
}