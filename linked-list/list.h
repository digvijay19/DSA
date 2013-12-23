#include <stdbool.h>

typedef struct{
	void* previous;
	void* data;
	void* next;
} Node;

typedef struct{
	Node* head;
	int length;
} doubleList;

doubleList* create();
Node* createNode(void* previous,void* next);
bool insert(doubleList* dList,int index,void* element);
bool remove(doubleList* dList,int index);