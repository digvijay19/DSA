#include "stack2.h"
#include <stdlib.h>
#include <memory.h>

void** getElement(Stack *stack){
	return stack->array+((stack->top)*sizeof(void*));
}

bool isFull(Stack *stack){
	if(stack->top==stack->length-1)	return true;
	return false; 
}
bool isEmpty(Stack *stack){
	if(stack->top==-1)	return true;
	return false; 
}

Stack* create(int length){
	Stack *temp = calloc(sizeof(Stack),1);
	temp->array = calloc(length,sizeof(void*));
	temp->length = length;
	temp->top = -1;
	return temp;
}

int push(Stack *stack,void *element){
	if(isFull(stack)){
		realloc(stack->array, stack->length*sizeof(void*));
		stack->length += stack->length;
	}
	stack->top++;
	*(getElement(stack)) = element;
	return 1;
}
void* pop(Stack* stack){
	void** element = getElement(stack);
    if(isEmpty(stack)) return NULL;
    stack->top--;
    return *(element);
};
void* top(Stack *stack){
	void** element = getElement(stack);
	return *element;
}