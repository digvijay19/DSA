typedef char String[256];

typedef int (*compare)(void* first, void* second) ;

void bubbleSort(void* base, int numberOfElements, int elementSize , compare comp);