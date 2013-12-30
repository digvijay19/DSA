#include "hashmap.h"
#include "privateHashmap.h"
#include <stdlib.h>

int compareKeysOfHashElements(void* one,void* two){
	HashElement *first,*second;
	first = (HashElement*)one;
	second = (HashElement*)two;
	return first->key - second->key;
}

int getSlotIndex(Hashmap* hash,void* key){
	return hash->hashCodeGenerator(key) % hash->bucket.capacity;
}

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
	HashElement *nextElement;
	Iterator it = getIteratorForList(list);
	while(it.hasNext(&it)){
		nextElement = it.next(&it);
		if(comp(nextElement->key , key) == 0)
			return nextElement;
	}
	return NULL;
}

// -------------------------------------------------------------------------------------

void assignAllSlots(ArrayList *list){
	int counter = 0;
	while(counter < list->capacity){
		addInArrayList(list, createSlot());
		counter++;
	}
}

Hashmap createHashmap(Comparator *comp,HashCodeGenerator *generator){
	Hashmap map;
	map.bucket = createArrayList(10);
	assignAllSlots(&map.bucket);
	map.comp = comp;
	map.hashCodeGenerator = generator;
	map.keys = createList();
	return map;
}

sList* getListFromHashMap(Hashmap* hash,void* key){
	slot *slotOfElement;
	int slotNumber = getSlotIndex(hash,key);
	slotOfElement = getFromArrayList(&hash->bucket,slotNumber);
	return slotOfElement->list;
}

void rehashIfNeeded(Hashmap* hash,void* key){
	sList *list;
	Iterator allKeys;
	HashElement *hashElement;
	int currentCapacity = hash->bucket.capacity;
	list = getListFromHashMap(hash, key);
	if(list->length < 2) return;

	allKeys = keys(hash);
	disposeHashmap(hash);
	hash->bucket = createArrayList(currentCapacity*2);
	assignAllSlots(&hash->bucket);

	while(allKeys.hasNext(&allKeys)){
		hashElement = allKeys.next(&allKeys);
		put(hash, hashElement->key ,hashElement->value);
	}
}

int setValue(HashElement *hashElement,void* value){
	hashElement->value = value;
	return 1;
}

int put(Hashmap* hash,void* key,void* value){
	sList *list;
	Iterator keysIT;
	HashElement *hashElement;
	if(hash == NULL || key == NULL) return 0;

	rehashIfNeeded(hash,key);
	list = getListFromHashMap(hash, key);
	hashElement = getElementFromList(list,key,hash->comp);
	
	if(hashElement != NULL)	return setValue(hashElement,value);
	
	hashElement = createHashElement(key,value);
	return insertInList(list, hashElement,list->length);
}

void* getValue(Hashmap* hash,void* key){
	sList *list;
	HashElement* element;
	if(hash == NULL || key == NULL)	return NULL;
	list = getListFromHashMap(hash,key);
	element = getElementFromList(list,key,hash->comp);
	if(element == NULL)	return NULL;
	return element->value;
}

int removeFromHashMap(Hashmap *hash,void* key){
	sList *list;
	HashElement *hashElement;
	int index;
	if(hash == NULL || key == NULL)	return 0;
	list = getListFromHashMap(hash, key);
	hashElement = getElementFromList(list,key,hash->comp);
	index = getIndexFromList(list,hashElement,&compareKeysOfHashElements);
	return removeFromList(list,index);
}

Iterator keys(Hashmap *hash){
	Iterator listIT,keysIT,arrayIT;
	slot *slot;
	sList *keys = hash->keys;
	disposeList(keys);
	keys = createList();

	arrayIT = getIterator(&hash->bucket);
	while(arrayIT.hasNext(&arrayIT)){
		slot = arrayIT.next(&arrayIT);
		listIT = getIteratorForList(slot->list);
		while(listIT.hasNext(&listIT)){
			insertInList(keys, listIT.next(&listIT),keys->length);
		}
	}
	keysIT = getIteratorForList(keys);
	return keysIT;
}

void disposeSlot(slot *slot){
	disposeList(slot->list);
	free(slot);
}

void disposeHashmap(Hashmap *hash){
	Iterator it = getIterator(&hash->bucket);
	while(it.hasNext(&it))
		disposeSlot(it.next(&it));
	disposeArraylist(&hash->bucket);
}