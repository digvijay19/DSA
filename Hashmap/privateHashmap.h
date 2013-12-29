#include "./include/singly-List.h"

typedef struct{
	sList *list;
} slot;

typedef struct{
	void* key;
	void* value;
} HashElement;

slot* createSlot();
HashElement *getHashElement(void* key,void* value);