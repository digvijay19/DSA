#include "../iterator.h"

typedef int comparator(void* nodeData,void* parentData);

typedef struct{
	void* root;
	comparator *comp;
} Tree;

Tree create(comparator* areEqual);

int insertInTree(Tree *tree, void *parentData, void *data);

void* getRootData(Tree *tree);

Iterator getChildren(Tree *tree, void *parentData);