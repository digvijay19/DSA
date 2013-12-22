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
    ASSERT(dlist->head->previous == NULL);
    ASSERT(dlist->head->next == NULL);
}
void test_insert_three_elements_and_check_the_next_of_each(){
    doubleList* dlist = create();
    Node *one,*two,*three;
    int _5 = 5;
    insert(dlist, 0, &_5);
    insert(dlist, 1, &_5);
    insert(dlist, 2, &_5);
    one = dlist->head;
    two = one->next;
    three = two->next;
    ASSERT(dlist->length == 3);
    ASSERT(one->next == two);
    ASSERT(two->next == three);
    ASSERT(three->next == NULL);
}
void test_insert_elements_and_check_data_of_each(){
    doubleList* dlist = create();
    Node *one,*two,*three;
    int _1 = 1;
    int _2 = 2;
    int _3 = 3;
    insert(dlist, 0, &_1);
    insert(dlist, 1, &_2);
    insert(dlist, 2, &_3);
    one = dlist->head;
    two = one->next;
    three = two->next;
    ASSERT(dlist->length == 3);
    ASSERT(*(int*)one->data == 1);
    ASSERT(*(int*)two->data == 2);
    ASSERT(*(int*)three->data == 3);
}
void test_insert_elements_of_different_data_types(){
    doubleList* dlist = create();
    Node *one,*two;
    int _1 = 1;
    char _a = 'a';
    insert(dlist, 0, &_1);
    insert(dlist, 1, &_a);
    one = dlist->head;
    two = one->next;
    ASSERT(*(int*)one->data == 1);
    ASSERT(*(char*)two->data == 'a');
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
void test_delete_2nd_element(){
    doubleList* dlist = create();
    int _1 = 1,_2 = 2,_3 = 3;
    Node *one,*two;
    insert(dlist, 0, &_1);
    insert(dlist, 1, &_2);
    insert(dlist, 2, &_3);
    ASSERT(remove(dlist, 1));
    ASSERT(2 == dlist->length);
    one = dlist->head;
    two= one->next;
    ASSERT(3 == *(int*)two->data);
}
void test_delete_when_index_not_present(){
    doubleList* dlist = create();
    int _1 = 1,_2 = 2,_3 = 3;
    Node *one,*two;
    insert(dlist, 0, &_1);
    insert(dlist, 1, &_2);
    insert(dlist, 2, &_3);
    ASSERT(remove(dlist, 4) == false);
    ASSERT(3 == dlist->length);
}
void test_delete_when_list_is_empty(){
    doubleList* dlist = create();
    Node *one,*two;
    ASSERT(remove(dlist, 0) == false);
    ASSERT(0 == dlist->length);
}
void test_delete_when_index_passed_is_negative(){
    doubleList* dlist = create();
    int _1 = 1,_2 = 2,_3 = 3;
    Node *one,*two;
    insert(dlist, 0, &_1);
    insert(dlist, 1, &_2);
    insert(dlist, 2, &_3);
    ASSERT(remove(dlist,-1) == false);
    ASSERT(3 == dlist->length);
}