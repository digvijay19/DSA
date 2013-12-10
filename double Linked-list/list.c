#include "list.h"
#include <stdlib.h>

Node* createNode(void* previous,void* next){
	Node* node = calloc(1,sizeof(Node));
	node->previous = previous;
	node->next = next;
	return node;
}
doubleList* create(){
	doubleList* list = calloc(1,sizeof(doubleList));
	list->length = 0;
	list->head = NULL;
	return list;
}
bool insert(doubleList* dList,int index,void * element){
	int i;
	Node *previousNode,*nextNode,*newNode;
	if(index > dList->length)	return false;
	
	dList->length++;
	newNode = createNode(NULL,NULL);
	newNode->data = element;
	
	previousNode = dList->head;
	if(dList->head == NULL){
		nextNode = NULL;
		dList->head = newNode;
	}
	else
		nextNode = previousNode->next;

	for(i=1;i<index;i++){
		nextNode = previousNode->next;
		previousNode = nextNode->previous;
	}
	newNode->previous = previousNode;
	if(previousNode != NULL)	previousNode->next = newNode;
	newNode->next = nextNode;
	if(nextNode != NULL)	nextNode->previous = newNode;

	return true;
}