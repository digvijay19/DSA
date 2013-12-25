#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* getNextElement(Stack *stack){
	return stack->array+((stack->top+1)*stack->sizeOfElement);
}
void* getTopElement(Stack *stack){
	return stack->array+(stack->top*stack->sizeOfElement);
}

Stack* create(int sizeOfElement,int maxElements){
	Stack *temp = calloc(sizeof(Stack),1);
	temp->array = calloc(maxElements,sizeOfElement);
	temp->sizeOfElement = sizeOfElement;
	temp->maxElements = maxElements;
	temp->top = -1;
	return temp;
}
int push(Stack *stack,void *element){
	void* newElement;
	if(isFull(stack)){
		stack->maxElements += stack->maxElements;
		realloc(stack->array,stack->maxElements*stack->sizeOfElement);
	}
	newElement = getNextElement(stack);
	memcpy (newElement, element, stack->sizeOfElement);
	stack->top++;
	return 1;
}
void* pop(Stack *stack){
	void* element;
	if(isEmpty(stack))	return NULL;
	element = getTopElement(stack);
	stack->top--;
	return element;
}
void* top(Stack *stack){
	void* element = getTopElement(stack);
	return element;
}
bool isEmpty(Stack *stack){
	if(stack->top==-1)	return true;
	return false; 
}
bool isFull(Stack *stack){
	if(stack->top==stack->maxElements-1)	return true;
	return false; 
}