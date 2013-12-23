#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool isEmpty(Queue* queue){
	if(queue->front == queue->rear) return true;
	return false;
}

bool isFull(Queue* queue){
	if(queue->rear == queue->length)
		queue->rear = -1;
	if(queue->rear == queue->front-1)
		return true;
	return false;
}

Queue* create(int size,int length){
	Queue *queue = calloc(1,sizeof(Queue));
	queue->base = calloc(length,size);
	queue->length =  length;
	queue->typeSize = size;
	queue->front = 0;
	queue->rear = 0;
	return queue;
}
bool enqueue(Queue *queue,void* element){
	if(isFull(queue)) return false;
	if(queue->rear == -1) queue->rear = 0;
	else
		queue->rear++;
	memcpy(queue->base+((queue->rear-1)*queue->typeSize),element,queue->typeSize);
	return true;
}
void* dequeue(Queue *queue){
	void * element;
	if(queue->front == queue->length-1) queue->front = 0;
	if(isEmpty(queue)) return NULL;
	element = queue->base+(queue->front*queue->typeSize);
	queue->front++;
	
	return element;
}