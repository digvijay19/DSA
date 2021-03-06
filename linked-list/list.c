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
bool insert(doubleList* dList,int index,void* element){
	int i=1;
	Node* newNode = createNode(NULL,NULL);
	Node *previousNode;
	Node *nextNode = NULL;
	
	if(index > dList->length) return false;
	newNode->data = element;
	if(dList->head == NULL){
		dList->head = newNode;
		dList->length++;
		return true;
	}
	previousNode = dList->head;
	while(i < index){
		previousNode = previousNode->next;
		if(previousNode!= NULL)	nextNode = previousNode->next;
		i++;
	}
	previousNode->next = newNode;
	if(nextNode != NULL)	nextNode->previous = newNode;
	newNode->previous = previousNode;
	newNode->next = nextNode;
	dList->length++;
	return true;
}
bool remove(doubleList* dList,int index){
	int i;
	Node *previousNode,*nextNode;
	Node *temp = dList->head;
	if(index >= dList->length || index < 0) return false;
	for(i=0;i<index;i++){
		temp = temp->next;
	}
	previousNode = temp->previous;
	nextNode = temp->next;
	free(temp);
	if(previousNode != NULL)	previousNode->next = nextNode;
	if(nextNode != NULL)	nextNode->previous = previousNode;
	dList->length--;
	return true;
}