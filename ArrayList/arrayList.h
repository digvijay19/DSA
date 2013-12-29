#include "../iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int compareFunc(void* one,void* two);

ArrayList createArrayList(int capacity);

int insertInArrayList(ArrayList *list, int index, void* data);

int addInArrayList(ArrayList *list, void* data);

void* removeFromArrayList(ArrayList *list, int index );

void* getFromArrayList(ArrayList *list, int index);

int searchInArrayList(ArrayList *list,void* data,compareFunc *comp);

void disposeArraylist(ArrayList *list);