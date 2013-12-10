#include <stdbool.h>

typedef struct{
	void *base;
	int length;
	int typeSize;
	int front;
	int rear;
} Queue;

Queue* create(int size,int length);
bool enqueue(Queue *queue,void* element);
void* dequeue(Queue *queue);

bool isEmpty(Queue* queue);
bool isFull(Queue* queue);