#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *integerQueue;
int areEqual(Queue a, Queue b){
	int result = a.rear == b.rear && a.length == b.length && a.typeSize == b.typeSize;
	if(!result) return result;
	return 0 == memcmp( a.base , b.base , a.length*a.typeSize );
};

void test_create_queue_of_two_integers(){
	int two_zeroes[] = {0,0};
	Queue b = {two_zeroes,2,sizeof(int),-1};
	integerQueue = create(sizeof(int),2);
	ASSERT(areEqual(*integerQueue,b));
	free(integerQueue);
}
void test_enqueue_of_integer(){
	int two_zeroes[] = {1,0};
	bool result;
	int element = 1;
	Queue b = {two_zeroes,2,sizeof(int),0};
	integerQueue = create(sizeof(int),2);
	result = enqueue(integerQueue,&element);
	ASSERT(areEqual(*integerQueue,b) && result==true);
	free(integerQueue);
}
void test_when_full_do_not_enqueue(){
	bool result;
	int two_zeroes[] = {1,1};
	int element = 1;
	Queue b = {two_zeroes,2,sizeof(int),1};
	integerQueue = create(sizeof(int),2);
	result = enqueue(integerQueue,&element);
	result = enqueue(integerQueue,&element);
	result = enqueue(integerQueue,&element);
	ASSERT(areEqual(*integerQueue,b) && result==false);
	free(integerQueue);
}
void test_dequeue_of_interger_queue_gives_dequeued_element(){
	bool result;
	int element = 1;
	int removedElement;
	integerQueue = create(sizeof(int),2);
	result = enqueue(integerQueue,&element);
	result = enqueue(integerQueue,&element);
	removedElement = *(int*)dequeue(integerQueue);
	ASSERT(removedElement == 1);
	free(integerQueue);
}
void test_dequeue_of_interger_queue(){
	bool result;
	int two_zeroes[] = {1,2};
	int _1 = 1;
	int _2 = 2;
	int removedElement;
	Queue b = {two_zeroes,2,sizeof(int),1};
	integerQueue = create(sizeof(int),2);
	result = enqueue(integerQueue,&_1);
	result = enqueue(integerQueue,&_1);
	removedElement = *(int*)dequeue(integerQueue);
	result = enqueue(integerQueue,&_2);
	ASSERT(areEqual(*integerQueue,b));
	free(integerQueue);
}
void test_dequeue_when_empty(){
	integerQueue = create(sizeof(int),2);
	ASSERT(dequeue(integerQueue)==NULL);
}