#include "./include/arraylist.h"
#include "../iterator.h"

typedef int Comparator(void* element,void* data);
typedef int HashCodeGenerator(void* element);

typedef struct{
	ArrayList bucket;
	Comparator *comp;
	HashCodeGenerator *hashCodeGenerator;
	void* keys;
} Hashmap;

Hashmap createHashmap(Comparator *comp,HashCodeGenerator *generator);

int put(Hashmap* hash,void* key,void* value);

void* getValue(Hashmap* hash,void* key);

int removeFromHashMap(Hashmap *hash,void* key);

Iterator keys(Hashmap *hash);

void disposeHashmap(Hashmap *hash);