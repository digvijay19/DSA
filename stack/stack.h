#include <stdbool.h>
typedef char String[256];
typedef struct{
	void *array;
	int top;
	int sizeOfElement;
	int maxElements;
} Stack;

Stack* create(int sizeOfElement,int maxElements);
int push(Stack *stack,void *element);
void* pop(Stack *stack);
void* top(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);