#include "singly-List.h"
#include <stdlib.h>
Node* createNode(void* element){
	Node* node = calloc(1,sizeof(Node));
	node->element = element;
	node->next = NULL;
	return node;
}

sList* createList(){
	sList *list = calloc(1,sizeof(sList));
	list->head = NULL;
	list->length = 0;
	return list;
}

int insert(sList* list,Node* node,int position){
	int i;
	Node *tempNode,*previousNode,*nextNode;
    if(list == NULL) return 0;
	if(position < 0 || position > list->length) return 0;

	if(list->head == NULL){
		list->head = node;
		list->length++;
		return 1;
	}
	previousNode = list->head;
	nextNode = previousNode->next;
	for(i=0;i<position-1;i++){
		previousNode = nextNode;
		nextNode = nextNode->next;
	}
	previousNode->next = node;
	node->next = nextNode;
	list->length++;
	return 1;
}

int remove(sList* list,int position){
    int i;
    Node *prevoiusNode,*toDelete;
    if(list == NULL) return 0;
    if(position < 0 || position >= list->length) return 0;
    
    prevoiusNode = list->head;
    
    for(i=0;i<position-1;i++){
    	prevoiusNode = prevoiusNode->next;
    }
    if(i==0){
    	list->head = prevoiusNode->next;
    	free(prevoiusNode);
    	list->length--;
    	return 1;
    }
    
    if(toDelete->next != NULL)
    	prevoiusNode->next = toDelete->next;
    else
    	prevoiusNode->next = NULL;
    
    free(toDelete);
    list->length--;
    return 1;
};