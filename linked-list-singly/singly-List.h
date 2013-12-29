#include "../iterator.h"

typedef int compare(void* element,void* toSearch);
typedef struct{
	void* element;
	void* next;
} Node;

typedef struct{
	void* head;
	int length;
} sList;

Node* createNodeOfList(void* element);
sList* createList();
int insertInList(sList* list,void* element,int position);
int removeFromList(sList* list,int position);
Iterator getIteratorForList(sList *list);
int getIndexFromList(sList *list,void* data,compare *comp);
void disposeList(sList *list);