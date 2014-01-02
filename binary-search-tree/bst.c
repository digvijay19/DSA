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

BSTNode* getNodeToInsert(BSTNode *root,Comapartor *comp,void* data){
	int compareResult = comp(root->data,data);
	if(compareResult == 0)	return NULL;
	if(compareResult > 0){
		if(root->left == NULL) return root;
		return getNodeToInsert(root->left,comp,data);
	}
	if(root->right == NULL) return root;
	return getNodeToInsert(root->right, comp, data); 
}

int insertInBST(BST* tree,void* data){
	BSTNode* nodeToInsert,*newNode;
	newNode = createBSTNode(data);
	if(tree->root == NULL){
		tree->root = newNode;
		return 1;
	}
	nodeToInsert = getNodeToInsert(tree->root,tree->comp,data);
	
	if(nodeToInsert == NULL)	return 0;
	if(tree->comp(nodeToInsert->data,data) > 0)
		nodeToInsert->left = newNode;
	else
		nodeToInsert->right = newNode;
	
	return 1;
}

int searchInAllNodes(BSTNode* root,Comapartor *comp,void* data){
	int compareResult;
	if(root == NULL) return 0;
	compareResult = comp(root->data,data);
	if( compareResult == 0) return 1;
	if(compareResult > 0)
		return searchInAllNodes(root->left,comp,data);
	return searchInAllNodes(root->right,comp,data);
}
int searchInBST(BST* tree,void* data){
	BSTNode* node = tree->root;
	return searchInAllNodes(node,tree->comp,data);
}