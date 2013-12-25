#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack *stack;
void setup(){
	stack = create();
}
void tearDown(){
	disposeStack(stack);
}
void test_push_element_into_stack(){
	int element = 10;
	int *elementPtr = &element;
	ASSERT(1 == push(stack,elementPtr));
}
void test_push_multiple_elements_into_stack(){
	int element = 10;
	int *elementPtr = &element;
	ASSERT(1 == push(stack,elementPtr));
	ASSERT(1 == push(stack,elementPtr));
	ASSERT(1 == push(stack,elementPtr));
	ASSERT(1 == push(stack,elementPtr));
	ASSERT(4 == stack->list->length);
}
void test_pop_element_from_stack(){
	int element = 10;
	int *elementPtr = &element;
	ASSERT(1 == push(stack,elementPtr));
	ASSERT(1 == stack->list->length);
	ASSERT(1 == pop(stack));
	ASSERT(0 == stack->list->length);
}
void test_pop_when_stack_is_empty(){
	ASSERT(0 == pop(stack));
}
void test_top_when_one_element_present(){
	int element = 10;
	ASSERT(1 == push(stack,&element));
	ASSERT(element =*(int*) top(stack));
}
void test_top_when_multiple_elements_present(){
	int element = 10;
	int twenty = 20;
	ASSERT(1 == push(stack,&element));
	ASSERT(1 == push(stack,&twenty));
	ASSERT(twenty =*(int*) top(stack));
}
void test_top_when_stack_is_empty(){
	ASSERT(top(stack) == NULL);
}
void test_top_when_stack_is_null(){
	ASSERT(top(NULL) == NULL);
}
void test_push_when_stack_is_null(){
	int element = 10;
	ASSERT(0 == push(NULL,&element));
}
void test_pop_when_stack_is_null(){
	int element = 10;
	ASSERT(0 == pop(NULL));
}
void test_isEmpty_when_stack_is_null(){
	ASSERT(0 == isEmpty(NULL));
}
void test_isEmpty_when_not_empty(){
	int element = 10;
	ASSERT(1 == push(stack,&element));
	ASSERT(0 == isEmpty(stack));
}
void test_isEmpty_when_empty(){
	ASSERT(1 == isEmpty(stack));
}