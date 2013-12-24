#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
void test_add_element_when_list_is_empty(){
	int result = add(internsPtr, &prateek);

	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_add_multiple_elements() {
	add(internsPtr, &prateek);
	add(internsPtr, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}
void test_add_list_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	add(listPtr, &prateek);
	add(listPtr, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}
void test_should_not_add_when_list_is_null() {
	int result = add(NULL, &prateek);
	ASSERT(result == FAILURE);
}
void test_remove_element(){
	Intern *result ;
	add(internsPtr, &prateek);
	result = remove(internsPtr,0); 
	ASSERT(result == &prateek);
	ASSERT(internsPtr->length == 0);
}
void test_remove_element_when_multiple_elements_present(){
	Intern *result ;
	add(internsPtr, &prateek);
	add(internsPtr, &ji);
	result = remove(internsPtr,0); 
	ASSERT(result == &prateek);
	ASSERT(&ji == get(internsPtr, 0));
	ASSERT(internsPtr->length == 1);
}
void test_remove_element_when_index_element_not_present(){
	void* result;
	add(internsPtr, &prateek);
	add(internsPtr, &ji);
	result = remove(internsPtr, 3);
	ASSERT(result == NULL);
}
void test_remove_element_when_index_is_negative(){
	void* result;
	add(internsPtr, &prateek);
	add(internsPtr, &ji);
	result = remove(internsPtr, -1);
	ASSERT(result == NULL);
}
int compareInt(void *one,void* two){
	return (*(int*)one - *(int*)two);
}
void test_search_integer_from_list(){
	int result;
	ArrayList list = create(2);
	ArrayList *listPtr = &list;
	int _10 = 10;
	int _20 = 20;
	add(listPtr, &_10);
	add(listPtr, &_20);
	result = search(listPtr,&_20, &compareInt);
	ASSERT(result == 2);
}
void test_search_when_element_not_present(){
	int result;
	ArrayList list = create(2);
	ArrayList *listPtr = &list;
	int _10 = 10;
	int _20 = 20;
	int toSeach = 30;
	add(listPtr, &_10);
	add(listPtr, &_20);
	result = search(listPtr,&toSeach, &compareInt);
	ASSERT(result == 0);
}