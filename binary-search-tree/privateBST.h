#include "bst.h"

typedef struct BSTNode{
	void* data;
	struct BSTNode* parent;
	struct BSTNode* left;
	struct BSTNode* right;
} BSTNode;

BSTNode* createBSTNode(void* data);
BSTNode* getNode(BST *tree,void* data);