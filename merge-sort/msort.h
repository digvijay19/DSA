typedef char String[256];

typedef int (*compare)(void* first, void* second) ;

void mSort(void** base, int numberOfElements, compare comp);