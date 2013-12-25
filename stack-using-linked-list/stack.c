#include "stack.h"
#include <stdlib.h>

Stack* create(){
	Stack *stack = calloc(1,sizeof(Stack));
	stack->list = createList();
	return stack;
}

int push(Stack *stack,void *element){
	if(stack == NULL)	return 0;
	return insert(stack->list,element,stack->list->length);
}

int pop(Stack *stack){
	if(stack == NULL)	return 0;
	return remove(stack->list,stack->list->length-1);
}
bool isEmpty(Stack* stack){
	if(stack == NULL)	return 0;
    return stack->list->length == 0;
}

void* top(Stack *stack){
    Node* currentNode;
    if(stack == NULL)	return NULL;
    if(isEmpty(stack))
        return NULL;

    currentNode = stack->list->head;
    while(currentNode->next!=NULL)
        currentNode = currentNode->next;

    return currentNode->element;
}

void disposeStack(Stack* stack){
    free(stack->list);
    free(stack);
}