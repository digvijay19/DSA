#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Queue *integerQueue;
Queue *floatQueue;
Queue *doubleQueue;
Queue *charQueue;
Queue *StringQueue;
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
void test_create_queue_of_two_floats(){
	float two_zeroes[] = {0.0,0.0};
	Queue b = {two_zeroes,2,sizeof(float),-1};
	floatQueue = create(sizeof(float),2);
	ASSERT(areEqual(*floatQueue,b));
	free(floatQueue);
}
void test_create_queue_of_two_double(){
	double two_zeroes[] = {0.0,0.0};
	Queue b = {two_zeroes,2,sizeof(double),-1};
	doubleQueue = create(sizeof(double),2);
	ASSERT(areEqual(*doubleQueue,b));
	free(doubleQueue);
}
void test_create_queue_of_two_chars(){
	char two_nulls[] = {'\0','\0'};
	Queue b = {two_nulls,2,sizeof(char),-1};
	charQueue = create(sizeof(char),2);
	ASSERT(areEqual(*charQueue,b));
	free(charQueue);
}
void test_create_queue_of_two_Strings(){
	String two_zeroes[] = {"",""};
	Queue b = {two_zeroes,2,sizeof(String),-1};
	doubleQueue = create(sizeof(String),2);
	ASSERT(areEqual(*doubleQueue,b));
	free(doubleQueue);
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
void test_enqueue_of_float(){
	float two_zeroes[] = {1.1,0.0};
	bool result;
	float element = 1.1;
	Queue b = {two_zeroes,2,sizeof(float),0};
	floatQueue = create(sizeof(float),2);
	result = enqueue(floatQueue,&element);
	ASSERT(areEqual(*floatQueue,b) && result==true);
	free(floatQueue);
}
void test_enqueue_of_character(){
	char two_zeroes[] = {'a','\0'};
	bool result;
	char element = 'a';
	Queue b = {two_zeroes,2,sizeof(char),0};
	floatQueue = create(sizeof(char),2);
	result = enqueue(floatQueue,&element);
	ASSERT(areEqual(*floatQueue,b) && result==true);
	free(floatQueue);
}
void test_enqueue_of_string(){
	String two_zeroes[] = {"digs",""};
	bool result;
	String element = "digs";
	Queue b = {two_zeroes,2,sizeof(String),0};
	floatQueue = create(sizeof(String),2);
	result = enqueue(floatQueue,&element);
	ASSERT(areEqual(*floatQueue,b) && result==true);
	free(floatQueue);
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
void test_dequeue_of_float_queue(){
	bool result;
	float element = 1.1;
	float removedElement;
	floatQueue = create(sizeof(float),2);
	result = enqueue(floatQueue,&element);
	result = enqueue(floatQueue,&element);
	removedElement = *(float*)dequeue(floatQueue);
	ASSERT(removedElement == 1.1f);
	free(floatQueue);
}
void test_dequeue_of_character_queue(){
	bool result;
	char element = 'a';
	char removedElement;
	floatQueue = create(sizeof(char),2);
	result = enqueue(floatQueue,&element);
	result = enqueue(floatQueue,&element);
	removedElement = *(char*)dequeue(floatQueue);
	ASSERT(removedElement == 'a');
	free(floatQueue);
}
void test_dequeue_of_String_queue(){
	bool result;
	String element = "digs";
	floatQueue = create(sizeof(String),2);
	result = enqueue(floatQueue,&element);
	result = enqueue(floatQueue,&element);
	ASSERT(strcmp(dequeue(floatQueue),"digs")==0);
	free(floatQueue);
}
void test_dequeue_when_empty(){
	integerQueue = create(sizeof(int),2);
	ASSERT(dequeue(integerQueue)==NULL);
}