#include "testUtils.h"
#include "bst.h"
#include "privateBST.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;
int compareInts(void* first,void* second){
	return *(int*)first - *(int*)second;
}

BST bst;

void setup(){
	bst = createBST(&compareInts);
}

void test_insert_root_node_in_BST(){
	int element = 10;
	BSTNode *root;
	ASSERT(insert(&bst, &element) == SUCCESS);
	root = bst.root;
	ASSERT(root->data = &element);
}
