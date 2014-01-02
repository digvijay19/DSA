#include "bst.h"
#include "privateBST.h"
#include <stdlib.h>

BSTNode* createBSTNode(void* data){
	BSTNode* newNode = malloc(sizeof(BSTNode));
	newNode->data = data;
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// ==============================================================================

BST createBST(Comapartor *comp){
	BST tree;
	tree.comp = comp;
	tree.root = NULL;
	return tree;
}

int insert(BST* tree,void* data){
	BSTNode *newNode = createBSTNode(data);
	if(tree->root == NULL){
		tree->root = newNode;
	}	
	return 1;
}