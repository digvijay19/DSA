#include "./include/singly-List.h"

typedef struct{
	sList *list;
} slot;

typedef struct{
	void* key;
	void* value;
} HashElement;

slot* createSlot();

HashElement *createHashElement(void* key,void* value);

HashElement* getElementFromList(sList *list,void* key,compare *comp);

int setValue(HashElement *element,void* value);