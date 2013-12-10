#include "testUtils.h"
#include "list.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_of_node(){
	Node expected = {NULL,NULL,NULL};
	Node *node = createNode(NULL,NULL);
	ASSERT(node->next == expected.next);
	ASSERT(node->data == expected.data);
	ASSERT(node->previous == expected.previous);
}
void test_create_double_linked_list(){
	doubleList *dList = create();
	ASSERT(dList->head == NULL);
	ASSERT(dList->length == 0);
}
void test_insert_element_to_empty_list(){
    doubleList* dlist = create();
    int _5 = 5;
    insert(dlist, 0, &_5);
    ASSERT(dlist->length == 1);
    ASSERT(*(int*)dlist->head->data == 5);
}
void test_insert_element_to_a_list_when_one_element_present(){
    doubleList* dlist = create();
    int _5 = 5;
    int _2 = 2;
    insert(dlist, 0, &_5);
    insert(dlist, 1, &_2);
    ASSERT(dlist->length == 2);
    ASSERT(*(int*)dlist->head->data == 5);
}
void test_insert_element_gives_true_when_inerted(){
	doubleList* dlist = create();
	int _5 = 5;
    ASSERT(insert(dlist, 0, &_5) == true);
}
void test_insert_element_gives_false_when_not_succesfull(){
	doubleList* dlist = create();
	int _5 = 5;
    ASSERT(insert(dlist, 1, &_5) == false);
}
void test_insert_elements_of_different_data_types(){
    doubleList* dlist = create();
    Node *one,*two;
	int _4 = 4;
	float _num = 4.2;
    
    insert(dlist, 0, &_4);
    insert(dlist, 1, &_num);
    one = dlist->head;
    two = one->next;
    ASSERT(*(int*)one->data == 4);
    ASSERT(*(float*)two->data == 4.2f);
}
// void test_insert_elements_and_set_next_and_previous_adreses(){
//     doubleList* dlist = create();
//     Node *one,*two;
// 	int _1 = 1;
// 	int _2 = 2;
// }