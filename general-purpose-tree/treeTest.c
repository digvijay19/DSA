#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;

int compareIntegers(void *a,void *b){
    return *(int*)a - *(int*)b;
}

void test_insert_root_node(){
    Tree tree = create(compareIntegers);
    int data = 10;
    ASSERT(SUCCESS == insertInTree(&tree, NULL, &data));
    ASSERT(&data == getRootData(&tree));
}
void test_insert_node_under_root_node(){
    Tree tree = create(compareIntegers);
    int numbers[] = {1,2,3};
    Iterator children;
    insertInTree(&tree, NULL, &numbers[0]);
    insertInTree(&tree, &numbers[0], &numbers[1]);
    insertInTree(&tree, &numbers[0], &numbers[2]);
    children = getChildren(&tree,&numbers[0]);
    ASSERT(*(int*)children.next(&children) == 2);
    ASSERT(*(int*)children.next(&children) == 3);
}