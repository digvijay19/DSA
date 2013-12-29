#include "hashmap.h"
#include "privateHashmap.h"
#include <stdlib.h>

slot* createSlot(){
	slot *slot = malloc(sizeof(slot));
	slot->list = createList();
	return slot;
}

HashElement *createHashElement(void* key,void*value){
	HashElement *hashElement = malloc(sizeof(HashElement));
	hashElement->key = key;
	hashElement->value = value;
	return hashElement;
}

HashElement* getElementFromList(sList *list,void* key,compare *comp){
	HashElement *temp;
	Iterator it = getIteratorForList(list);
	while(it.hasNext(&it)){
		temp = it.next(&it);
		if(comp(temp->key , key) == 0)
			return temp;
	}
	return NULL;
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
int getSlotIndex(Hashmap* hash,void* key){
	return hash->hashCodeGenerator(key) % hash->bucket.capacity;
}

sList* getListFromHashMap(Hashmap* hash,void* key){
	slot *slotOfElement;
	int slotNumber = getSlotIndex(hash,key);
	slotOfElement = getFromArrayList(&hash->bucket,slotNumber);
	return slotOfElement->list;
}

int put(Hashmap* hash,void* key,void* value){
	sList *list;
	HashElement *hashElement;
	list = getListFromHashMap(hash, key);
	hashElement = getElementFromList(list,key,hash->comp);
	if(hashElement != NULL){
		hashElement->value = value;
		return 1;
	}
	hashElement = createHashElement(key,value);
	return insertInList(list, hashElement,list->length);
}

void* getValue(Hashmap* hash,void* key){
	sList *list = getListFromHashMap(hash,key);
	HashElement* element = getElementFromList(list,key,hash->comp);
	if(element == NULL)	return NULL;
	return element->value;
}