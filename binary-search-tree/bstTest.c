#include "testUtils.h"
#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;
const int FAIL = 0;

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
void test_insert_right_Of_root(){
	int rootData = 3;
	int rightData = 4;
	BSTNode *root;
	ASSERT(insertInBST(&bst, &rootData) == SUCCESS);
	ASSERT(insertInBST(&bst, &rightData) == SUCCESS);
	root = bst.root;
	ASSERT(root->right->data == &rightData);
}
void test_insert_left_and_right_to_root(){
	int rootData = 2;
	int leftData = 1;
	int rightData = 3;
	BSTNode *root;
	ASSERT(insertInBST(&bst, &rootData) == SUCCESS);
	ASSERT(insertInBST(&bst, &leftData) == SUCCESS);
	ASSERT(insertInBST(&bst, &rightData) == SUCCESS);
	root = bst.root;
	ASSERT(root->left->data == &leftData);
	ASSERT(root->right->data == &rightData);
}

void test_insert_left_at_level_2(){
	int rootData = 3;
	int leftLevelOne = 2;
	int leftLeveltwo = 1;
	BSTNode *root;
	ASSERT(insertInBST(&bst, &rootData) == SUCCESS);
	ASSERT(insertInBST(&bst, &leftLevelOne) == SUCCESS);
	ASSERT(insertInBST(&bst, &leftLeveltwo) == SUCCESS);
	root = bst.root;
	ASSERT(root->left->data == &leftLevelOne);
	ASSERT(root->left->left->data == &leftLeveltwo);
}

void test_search_data_in_root_node(){
	int rootData = 3;
	insertInBST(&bst, &rootData);
	ASSERT(searchInBST(&bst,&rootData) == SUCCESS);
}
void test_search_data_in_left_node(){
	int rootData = 3;
	int leftData = 2;
	insertInBST(&bst, &rootData);
	insertInBST(&bst, &leftData);
	ASSERT(searchInBST(&bst,&leftData) == SUCCESS);
}
void test_search_data_in_right_node(){
	int rootData = 3;
	int rightData = 4;
	insertInBST(&bst, &rootData);
	insertInBST(&bst, &rightData);
	ASSERT(searchInBST(&bst,&rightData) == SUCCESS);
}
void test_search_data_when_data_is_not_present(){
	int rootData = 3;
	int dataTosearch = 4;
	insertInBST(&bst, &rootData);
	ASSERT(searchInBST(&bst,&dataTosearch) == FAIL);
}
void test_do_not_insert_duplicate_data(){
	int rootData = 3;
	ASSERT(insertInBST(&bst, &rootData) == SUCCESS);
	ASSERT(insertInBST(&bst, &rootData) == FAIL);
}

void test_get_children_of_root(){
	int rootData = 3;
	int left = 2;
	int right = 4;
	Children children;
	insertInBST(&bst, &rootData);
	insertInBST(&bst, &left);
	insertInBST(&bst, &right);
	children = getChildren(&bst,&rootData);
	ASSERT(children.left == &left);
	ASSERT(children.right == &right);
}

void test_get_children_of_root_when_children_not_present(){
	int rootData = 3;
	Children children;
	insertInBST(&bst, &rootData);
	children = getChildren(&bst,&rootData);
	ASSERT(children.left == NULL);
	ASSERT(children.right == NULL);
}