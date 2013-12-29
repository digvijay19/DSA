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
	interns = createArrayList(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	disposeArraylist(internsPtr);	
}

void test_insert_element(){
	int result = insertInArrayList(internsPtr, 0, &prateek);

	Intern *actual = (Intern*)getFromArrayList(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insertInArrayList(internsPtr, 0, &prateek);
	insertInArrayList(internsPtr, 1, &ji);
	ASSERT(&prateek == getFromArrayList(internsPtr, 0));
	ASSERT(&ji == getFromArrayList(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = createArrayList(noOfElements);
	ArrayList *listPtr = &list;

	insertInArrayList(listPtr, 0, &prateek);
	insertInArrayList(listPtr, 1, &ji);

	ASSERT(&prateek == getFromArrayList(listPtr, 0));
	ASSERT(&ji == getFromArrayList(listPtr, 1));

	disposeArraylist(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insertInArrayList(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insertInArrayList(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insertInArrayList(internsPtr, 0, &prateek);
	insertInArrayList(internsPtr, 1, &ji);
	insertInArrayList(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == getFromArrayList(internsPtr, 0));
	ASSERT(&tanbirka == getFromArrayList(internsPtr, 1));
	ASSERT(&ji == getFromArrayList(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insertInArrayList(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
void test_add_element_when_list_is_empty(){
	int result = addInArrayList(internsPtr, &prateek);

	Intern *actual = (Intern*)getFromArrayList(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_add_multiple_elements() {
	addInArrayList(internsPtr, &prateek);
	addInArrayList(internsPtr, &ji);
	ASSERT(&prateek == getFromArrayList(internsPtr, 0));
	ASSERT(&ji == getFromArrayList(internsPtr, 1));
}
void test_add_list_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = createArrayList(noOfElements);
	ArrayList *listPtr = &list;

	addInArrayList(listPtr, &prateek);
	addInArrayList(listPtr, &ji);

	ASSERT(&prateek == getFromArrayList(listPtr, 0));
	ASSERT(&ji == getFromArrayList(listPtr, 1));

	disposeArraylist(listPtr);
}
void test_should_not_add_when_list_is_null() {
	int result = addInArrayList(NULL, &prateek);
	ASSERT(result == FAILURE);
}
void test_remove_element(){
	Intern *result ;
	addInArrayList(internsPtr, &prateek);
	result = removeFromArrayList(internsPtr,0); 
	ASSERT(result == &prateek);
	ASSERT(internsPtr->length == 0);
}
void test_remove_element_when_multiple_elements_present(){
	Intern *result ;
	addInArrayList(internsPtr, &prateek);
	addInArrayList(internsPtr, &ji);
	result = removeFromArrayList(internsPtr,0); 
	ASSERT(result == &prateek);
	ASSERT(&ji == getFromArrayList(internsPtr, 0));
	ASSERT(internsPtr->length == 1);
}
void test_remove_element_when_index_element_not_present(){
	void* result;
	addInArrayList(internsPtr, &prateek);
	addInArrayList(internsPtr, &ji);
	result = removeFromArrayList(internsPtr, 3);
	ASSERT(result == NULL);
}
void test_remove_element_when_index_is_negative(){
	void* result;
	addInArrayList(internsPtr, &prateek);
	addInArrayList(internsPtr, &ji);
	result = removeFromArrayList(internsPtr, -1);
	ASSERT(result == NULL);
}
int compareInt(void *one,void* two){
	return (*(int*)one - *(int*)two);
}
void test_search_integer_from_list(){
	int result;
	ArrayList list = createArrayList(2);
	ArrayList *listPtr = &list;
	int _10 = 10;
	int _20 = 20;
	addInArrayList(listPtr, &_10);
	addInArrayList(listPtr, &_20);
	result = searchInArrayList(listPtr,&_20, &compareInt);
	ASSERT(result == 1);
}
void test_search_when_element_not_present(){
	int result;
	ArrayList list = createArrayList(2);
	ArrayList *listPtr = &list;
	int _10 = 10;
	int _20 = 20;
	int toSeach = 30;
	addInArrayList(listPtr, &_10);
	addInArrayList(listPtr, &_20);
	result = searchInArrayList(listPtr,&toSeach, &compareInt);
	ASSERT(result == -1);
}