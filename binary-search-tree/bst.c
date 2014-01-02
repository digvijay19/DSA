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

BST createBST(Comparator *comp){
	BST tree;
	tree.comp = comp;
	tree.root = NULL;
	return tree;
}

int insertAtLeft(BSTNode *root,void* data){
	BSTNode *newNode = createBSTNode(data);
	root->left = newNode;
	return 1;
}
int insertAtRight(BSTNode *root,void* data){
	BSTNode *newNode = createBSTNode(data);
	root->right = newNode;
	return 1;
}

int insertNewNode(BSTNode *root,Comparator *comp,void* data){
	int compareResult = comp(root->data,data);
	
	if(compareResult == 0)	return 0;
	
	if(compareResult > 0){
		if(root->left == NULL)
			return insertAtLeft(root,data);
		return insertNewNode(root->left,comp,data);
	}

	if(root->right == NULL)
		return insertAtRight(root,data);
	return insertNewNode(root->right, comp, data); 
}

int insertInBST(BST* tree,void* data){
	BSTNode *newNode;
	if(tree->root == NULL){
		newNode = createBSTNode(data);
		tree->root = newNode;
		return 1;
	}
	return insertNewNode(tree->root,tree->comp,data);
}
BSTNode* getNodeFromBST(BSTNode* root,Comparator *comp,void* data){
	int compareResult;
	if(root == NULL) return NULL;
	compareResult = comp(root->data,data);
	if(compareResult == 0) return root;
	if(compareResult > 0)
		return getNodeFromBST(root->left,comp,data);
	return getNodeFromBST(root->right,comp,data);
}

BSTNode* getNode(BST *tree ,void* data){
	return getNodeFromBST(tree->root,tree->comp,data);
}

int searchInBST(BST* tree,void* data){
	BSTNode* node;
	node = getNode(tree,data);
	if(node == NULL) return 0;
	return 1;
}

Children getChildren(BST* tree,void* parentData){
	Children children = {NULL,NULL};
	BSTNode* node = getNode(tree, parentData);
	if(node->left != NULL)
		children.left = node->left->data;
	if(node->right != NULL)
		children.right = node->right->data;
	return children;
}

