#include "../../iterator.h"

typedef int compare(void* element,void* toSearch);
typedef struct{
	void* element;
	void* next;
} Node;

typedef struct{
	void* head;
	int length;
} sList;

Node* createNode(void* element);
sList* createList();
int insert(sList* list,void* element,int position);
int remove(sList* list,int position);
Iterator getIterator(sList *list);
void disposeList(sList *list);
int getIndex(sList *list,void* data,compare *comp);