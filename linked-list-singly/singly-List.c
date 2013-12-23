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
	if(list->head == NULL){
		list->head = node;
		list->length++;
		return 1;
	}
	previousNode = list->head;
	nextNode = previousNode->next;
	for(i=0;i<position;i++){
		if(nextNode != NULL){
			previousNode = nextNode;
			nextNode = nextNode->next;
		}
	}
	previousNode->next = node;
	node->next = nextNode;
	list->length++;
	return 1;
}

int remove(sList* list,int position){
    int i;
    Node *head,*deletedNode,*tempNode,*nextNode;
    if(position <= -1 || position >= list->length)
        return 0;
    head = list->head;
    for(i = 0 ; i < position ; i++)
        head = head->next;
    if(i == 0){
    	tempNode = list->head;
        tempNode = tempNode->next;
    	list->length--;
		free(head);
        return 1;
    }
    if(i == list->length - 1){
    	tempNode = list->head;   
        tempNode->next = NULL;
        list->length--;
        return 1;
    }
    tempNode = list->head;
    nextNode = tempNode->next;
    tempNode->element = nextNode->element;
    list->length--;
    return 1;
};