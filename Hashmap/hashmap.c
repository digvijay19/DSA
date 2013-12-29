#include "hashmap.h"
#include <stdlib.h>

Hashmap createHashmap(Comparator *comp,HashCodeGenerator *generator){
	Hashmap map;
	map.bucket = create(10);
	map.comp = comp;
	map.hashCodeGenerator = generator;
	return map;
}
int put(Hashmap* hash,void* key,void* value){
	
}