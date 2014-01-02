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

BST createBST(Comparator *comp){
	BST tree;
	tree.comp = comp;
	tree.root = NULL;
	return tree;
}

BSTNode* getNodeToInsert(BSTNode *root,Comparator *comp,void* data){
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

	newNode->parent = nodeToInsert;
	if(tree->comp(nodeToInsert->data,data) > 0)
		nodeToInsert->left = newNode;
	else
		nodeToInsert->right = newNode;
	return 1;
}
BSTNode* getNodeFromBST(BSTNode* root,Comparator *comp,void* data){
	int compareResult;
	if(root == NULL) return NULL;
	compareResult = comp(root->data,data);
	if( compareResult == 0) return root;
	if(compareResult > 0)
		return getNodeFromBST(root->left,comp,data);
	return getNodeFromBST(root->right,comp,data);
}

BSTNode* getNode(BST *tree ,void* data){
	BSTNode *root,*node;
	return getNodeFromBST(tree->root,tree->comp,data);
}

int searchInBST(BST* tree,void* data){
	BSTNode* node;
	node = getNode(tree,data);
	if(node == NULL) return 0;
	return 1;
}

BSTNode* getRootNode(BSTNode* root,Comparator *comp,void* data){
	int compareResult;
	if(root == NULL) return NULL;
	compareResult = comp(root->data,data);
	if(compareResult == 0) return root;
	if(compareResult > 0)
		return getRootNode(root->left,comp,data);
	return getRootNode(root->right,comp,data);
}

Children getChildren(BST* tree,void* parentData){
	Children children = {NULL,NULL};
	BSTNode* node = getRootNode(tree->root, tree->comp, parentData);
	if(node->left != NULL)
		children.left = node->left->data;
	if(node->right != NULL)
		children.right = node->right->data;
	return children;
}

