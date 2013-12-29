#include "arrayList.h"
#include <stdlib.h>

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

void shiftElementsToLeft(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = index; i < list->length-1; i++) {
			list->base[i] = list->base[i+1];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

// -------------------------------------------------------------------------------

int hasNextArrayElement(Iterator *it){
	ArrayList *list = it->list;
	if(it->position >= list->length)
		return 0;
	return 1;
}
void* nextArrayElement(Iterator *it){
	ArrayList *list = it->list;
	if(hasNextArrayElement(it))
		return list->base[it->position++];
	return NULL;
}
Iterator getIterator(ArrayList *list){
	Iterator it;
	it.list = list;
	it.position = 0;
	it.hasNext = &hasNextArrayElement;
	it.next = &nextArrayElement;
	return it;
}

// -------------------------------------------------------------------------------

ArrayList createArrayList(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

int insertInArrayList(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

int addInArrayList(ArrayList *list, void* data){
	if (list == NULL) return 0;

	increaseCapacity(list);

	list->base[list->length] = data;
	list->length++;

	return 1;
}

void* removeFromArrayList(ArrayList *list, int index ){
	void* toRemove;
	if(index >= list->length || index < 0 ) return NULL;
	toRemove = list->base[index];
	shiftElementsToLeft(list, index);
	
	list->length--;
	return toRemove;
}


void* getFromArrayList(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;
	return list->base[index];
}

int searchInArrayList(ArrayList *list,void* data,compareFunc *comp){
	Iterator it = getIterator(list);
	while(it.hasNext(&it)){
		if(comp(it.next(&it),data) == 0)
			return it.position-1;
	}
	return -1;
}

void disposeArraylist(ArrayList *list) {
	free(list->base);
}