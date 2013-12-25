#include "./include/singly-List.h"
#include <stdbool.h>

typedef struct{
    sList* list;
}Stack;

Stack* create();

int push(Stack *stack,void *element);
int pop(Stack *stack);

void* top(Stack *stack);
bool isEmpty(Stack *stack);
void disposeStack(Stack* stack);