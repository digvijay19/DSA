#include "../iterator.h"

typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int compareFunc(void* one,void* two);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

int add(ArrayList *list, void* data);

void* remove(ArrayList *list, int index );

void* get(ArrayList *list, int index);

int search(ArrayList *list,void* data,compareFunc *comp);

void dispose(ArrayList *list);