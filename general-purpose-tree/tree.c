#include "tree.h"
#include <stdlib.h>
#include "privateTree.h"

void* getTreeNodeByData(sList *list,void* data,comparator *comp){
	Iterator it = getIterator(list);
	TreeNode *treeNode;
	while(it.hasNext(&it)){
		treeNode = (TreeNode*)it.next(&it);
		if(0 == comp(treeNode->data,data))
			return treeNode;
		if(treeNode->child->head != NULL)
			return getTreeNodeByData(treeNode->child,data,comp);
	}
	return NULL;
}
TreeNode* createTreeNode(TreeNode* parent,void* data){
	TreeNode* treeNode = calloc(1,sizeof(TreeNode));
	treeNode->child = createList();
	treeNode->parent = parent;
	treeNode->data = data;
	return treeNode;
}

// ---------------------------------------------------------------------------------------

Tree create(comparator* areEqual){
	Tree tree = {NULL,areEqual};
	return tree;
}

void* getRootData(Tree *tree){
	TreeNode tempTree = *(TreeNode*)tree->root;
	return tempTree.data; 
}
void *nextSibling(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}

Iterator getChildren(Tree *tree, void *parentData){
	Iterator it;
	TreeNode *tempNode,*rootNode = tree->root;
	if(tree->comp(rootNode->data,parentData)==0)
		tempNode = rootNode;
	else
		tempNode = getTreeNodeByData(rootNode->child, parentData,tree->comp);
	it = getIterator(tempNode->child);
	it.next = &nextSibling;
	return it;
}

int insertInTree(Tree* tree, void *parentData, void *dataToInsert){
	TreeNode *parentNode, *newNode,*rootNode;
	if(NULL == parentData){
		tree->root = createTreeNode(NULL, dataToInsert);
		return 1;
	}
	rootNode = (TreeNode*)tree->root;

	if(0 == tree->comp(rootNode->data,parentData)){
		newNode = createTreeNode(rootNode, dataToInsert);
		return insert(rootNode->child, newNode,rootNode->child->length);
	}
	parentNode = getTreeNodeByData(rootNode->child,parentData, tree->comp);
	newNode = createTreeNode(parentNode, dataToInsert);
	return insert(parentNode->child, newNode,parentNode->child->length);
};