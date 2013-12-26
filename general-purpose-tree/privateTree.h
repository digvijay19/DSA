#include "./include/singly-List.h"
#include <stdlib.h>

typedef struct TreeNode{
    struct TreeNode* parent;
    sList *child;
    void* data;
} TreeNode;

TreeNode* createTreeNode(TreeNode* tree,void* parent);