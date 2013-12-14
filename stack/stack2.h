#include <stdbool.h>

typedef char String[256];
typedef struct{
	void *array;
	int top;
	int length;
} Stack;

Stack* create(int length);

int push(Stack *stack,void *element);
void* pop(Stack *stack);

void* top(Stack *stack);
bool isEmpty(Stack *stack);
bool isFull(Stack *stack);