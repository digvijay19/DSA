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
	TreeNode *parentNode,*rootNode = tree->root;
	if(tree->comp(rootNode->data,parentData)==0)
		parentNode = rootNode;
	else
		parentNode = getTreeNodeByData(rootNode->child, parentData,tree->comp);
	it = getIterator(parentNode->child);
	it.next = &nextSibling;
	return it;
}

int insertInTree(Tree* tree, void *parentData, void *dataToInsert){
	TreeNode *parentNode, *newNode,*rootNode;
	if(tree == NULL || dataToInsert == NULL) return 0;
	
	if(NULL == parentData){
		tree->root = createTreeNode(NULL, dataToInsert);
		return 1;
	}
	
	rootNode = (TreeNode*)tree->root;
	// if(search(tree,dataToInsert))	return 0;

	if(0 == tree->comp(rootNode->data,parentData)){
		newNode = createTreeNode(rootNode, dataToInsert);
		return insert(rootNode->child, newNode,rootNode->child->length);
	}
	parentNode = getTreeNodeByData(rootNode->child,parentData, tree->comp);
	newNode = createTreeNode(parentNode, dataToInsert);
	return insert(parentNode->child, newNode,parentNode->child->length);
};

int search(Tree *tree,void* elementToSearch){
	TreeNode *rootNode;
	if(tree == NULL || elementToSearch == NULL)
		return 0;
	rootNode = tree->root;
	if(tree->comp(elementToSearch,rootNode->data) == 0)
		return 1;
	if(getTreeNodeByData(rootNode->child, elementToSearch,tree->comp) != NULL)
		return 1;
	return 0;
}

int deleteFromTree(Tree *tree,void* dataToRemove){
	TreeNode *rootNode,*nodeToDelete,*parentNode;
	Iterator it;
	int result;
	if(tree == NULL || dataToRemove == NULL) return 0;
	rootNode = tree->root;
	nodeToDelete = getTreeNodeByData(rootNode->child, dataToRemove, tree->comp);
	if(nodeToDelete == NULL || nodeToDelete->child->length != 0)	return 0;
	
	parentNode = nodeToDelete->parent;
	it = getIterator(parentNode->child);
	
	while(it.hasNext(&it)){
		if(tree->comp(it.next(&it),nodeToDelete) == 0){
			result = remove(parentNode->child,it.position-1);
			break;
		}
	}
	return result;
}
void disposeNodes(sList *list){
	Iterator it ;
	sList* childList;
	TreeNode *treeNode;
	it = getIterator(list);
	while(it.hasNext(&it)){
		treeNode = (TreeNode*)it.next(&it);
		childList = (sList*)(treeNode->child);
		disposeNodes(childList);
	}
	disposeList(list);
}
void disposeTree(Tree* tree){
	TreeNode *root = tree->root;
	if(root != NULL){
		disposeNodes(root->child);
		free(root);
	}
}