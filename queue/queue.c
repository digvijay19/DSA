#include "queue.h"
#include <stdlib.h>
#include <string.h>

bool isFull(Queue *queue){
	if(queue->rear==queue->length-1)	return true;
	return false;
}
bool isEmpty(Queue *queue){
	if(queue->rear==-1)	return true;
	return false;
}

Queue* create(int elementSize,int length){
	Queue *queue = calloc(1,sizeof(Queue));
	queue->base = calloc(length,elementSize);
	queue->length = length;
	queue->typeSize = elementSize;
	queue->rear = -1;
	return queue;
}
bool enqueue(Queue *queue,void* element){
	if(isFull(queue)) return false;
	queue->rear++;
	memcpy(queue->base+(queue->rear*queue->typeSize),element,queue->typeSize);
	return true;
}
void* dequeue(Queue *queue){
	void* element;
	if(isEmpty(queue))	return NULL;
	element = queue->base+queue->typeSize;
	memmove(queue->base,queue->base+queue->typeSize,queue->typeSize*queue->rear);
	queue->rear--;
	return element;
}