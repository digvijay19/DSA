#include "queue.h"
#include <stdlib.h>

PQueue* createQueue(){
	PQueue* queue = calloc(1,sizeof(PQueue));
	queue->head = NULL;
	queue->length = 0;
	return queue;
};

Node* createNode(void* element,int priority){
	Node* node = calloc(1, sizeof(Node));
	node->element = element;
	node->priority = priority;
	node->next = NULL;
	return node;
};

int enqueue(PQueue* queue,void* element,int priority){
	Node* newNode = createNode(element,priority);
	Node *previous,*next;
	if(queue->head == NULL){
		queue->head = newNode;
		queue->length++;
		return 1;
	}
	previous = queue->head;
	next = previous->next;
	if(priority < previous->priority){
		queue->head = newNode;
		newNode->next = previous;
		queue->length++;
		return 1;
	}
	while(next != NULL && next->priority <= priority){
		previous = next;
		next = next->next;
	}
	previous->next = newNode;
	newNode->next = next;

	queue->length++;
	return 1;
}

void* dequeue(PQueue* queue){
	void* element;
	Node* toDequeue;
	if(queue->head == NULL)
		return NULL;
	toDequeue = queue->head;
	element = toDequeue->element;
	queue->head = toDequeue->next;
	free(toDequeue);
	queue->length--;
	return element;
}