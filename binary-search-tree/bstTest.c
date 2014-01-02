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
	ASSERT(insertInBST(&bst, &element) == SUCCESS);
	root = bst.root;
	ASSERT(root->data = &element);
}

void test_insert_left_Of_root(){
	int rootData = 3;
	int leftData = 2;
	BSTNode *root;
	ASSERT(insertInBST(&bst, &rootData) == SUCCESS);
	ASSERT(insertInBST(&bst, &leftData) == SUCCESS);
	root = bst.root;
	ASSERT(root->data = &rootData);
	ASSERT(root->left->data == &leftData);
}
