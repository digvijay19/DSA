#include "hashmap.h"
#include "privateHashmap.h"
#include <stdlib.h>

slot* createSlot(){
	slot *slot = malloc(sizeof(slot));
	slot->list = createList();
	return slot;
}

HashElement *getHashElement(void* key,void*value){
	HashElement *hashElement = malloc(sizeof(HashElement));
	hashElement->key = key;
	hashElement->value = value;
	return hashElement;
}

// -------------------------------------------------------------------------------------


Hashmap createHashmap(Comparator *comp,HashCodeGenerator *generator){
	Hashmap map;
	int index = 0;
	map.bucket = createArrayList(10);
	map.comp = comp;
	map.hashCodeGenerator = generator;
	while(index < map.bucket.capacity){
		addInArrayList(&map.bucket, createSlot());
		index++;
	}
	return map;
}
int put(Hashmap* hash,void* key,void* value){
	slot *slotOfElement;
	sList *list;
	HashElement *hashElement;
	int slotNumber = hash->hashCodeGenerator(key);
	slotOfElement = getFromArrayList(&hash->bucket,slotNumber);
	list = slotOfElement->list;
	hashElement = getHashElement(key,value);
	return insertInList(list, hashElement,list->length);
}