#include "testUtils.h"
#include "queue.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *integerQueue;

int areEqual(Queue a, Queue b){
	int result = a.rear == b.rear && a.front == b.front 
		&& a.length == b.length && a.typeSize == b.typeSize;
	if(!result) return result;
	return 0 == memcmp( a.base , b.base , a.length*a.typeSize );
};

void test_create_integer_queue_of_length_two(){
	int two_ints[] = {0,0};
	Queue b = {two_ints,2,sizeof(int),0,0};
	integerQueue = create(sizeof(4),2);
	ASSERT(areEqual(*integerQueue,b));
}
void test_enqueue_integer_queue(){
	int two_ints[] = {1,0};
	bool result;
	int element = 1;
	Queue b = {two_ints,2,sizeof(int),0,1};
	integerQueue = create(sizeof(4),2);
	enqueue(integerQueue,&element);
	ASSERT(areEqual(*integerQueue,b));
}
void test_dequeue_integer_queue(){
	int two_ints[] = {1,0};
	int result;
	int element = 1;
	Queue b = {two_ints,2,sizeof(int),1,1};
	integerQueue = create(sizeof(4),2);
	enqueue(integerQueue,&element);
	result = *(int*)dequeue(integerQueue);
	ASSERT(areEqual(*integerQueue,b));
}
void test_does_not_dequeue_empty_integer_queue(){
	integerQueue = create(sizeof(4),2);
	ASSERT(dequeue(integerQueue)==NULL);
}
void test_does_not_enqueue_full_integer_queue(){
	int element = 1;
	bool result;
	integerQueue = create(sizeof(4),2);
	enqueue(integerQueue,&element);
	enqueue(integerQueue,&element);
	result = enqueue(integerQueue,&element);
	ASSERT(result==false);
}
void test_enqueue_integer_queue_in_circular_way(){
	int _1 = 1;
	int _2 = 2;
	int result;
	int two_ints[] = {2,1};
	Queue b = {two_ints,2,sizeof(int),1,1};
	integerQueue = create(sizeof(4),2);
	enqueue(integerQueue,&_1);
	enqueue(integerQueue,&_1);
	result = *(int*)dequeue(integerQueue);
	enqueue(integerQueue,&_2);
	ASSERT(areEqual(*integerQueue,b));
}
void test_dequeue_integer_queue_in_circular_way(){
	int _1 = 1;
	int _2 = 2;
	int result,i;
	int expected[] = {2,2,1,1};
	int four_ints[] = {1,1,1,1};
	Queue b = {expected,4,sizeof(int),1,2};
	Queue a = {four_ints,4,sizeof(int),0,4};
	dequeue(&a);
	dequeue(&a);
	dequeue(&a);
	dequeue(&a);
	enqueue(&a,&_2);
	enqueue(&a,&_2);
	dequeue(&a);
	for(i=0;i<4;i++){
		printf("=======>%d\n",*(int*)(a.base+(i*4)));
	}
	printf("=======>front = %d\n",a.front);
	printf("=======>rear = %d\n",a.rear);
	ASSERT(areEqual(a,b));
}