#include "testUtils.h"
#include "stack2.h"
#include <stdlib.h>
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(Stack a, Stack b){
	int result = a.top == b.top && a.length == b.length;
	if(!result) return result;
	return 0 == memcmp(a.array,b.array,a.length*4);
};

void test_create_stack_of_two_integers(){
	int two_zeroes[] = {0,0};
	Stack b = {two_zeroes,-1,2};
	Stack *stack = create(2);
	ASSERT(areEqual(*stack,b));
	free(stack);
}
void test_create_stack_of_two_doubles(){
	double two_zeroes[] = {0,0};
	Stack b = {two_zeroes,-1,2};
	Stack *stack = create(2);
	ASSERT(areEqual(*stack,b));
	free(stack);
}
void test_create_stack_of_two_chars(){
	char two_chars[] = {'\0','\0'};
	Stack b = {two_chars,-1,2};
	Stack *stack = create(2);
	ASSERT(stack->length == 2);
	ASSERT(stack->top == -1);
	free(stack);
}
void test_create_stack_of_two_Strings(){
	String two_zeroes[] = {"\0","\0"};
	Stack b = {two_zeroes,-1,2};
	Stack *stack = create(2);
	ASSERT(areEqual(*stack,b));
	free(stack);
}
void test_push_integer_in_stack(){
	int element = 1;
	Stack *stack = create(1);
	push(stack,&element);
	ASSERT(1 == **(int**)getElement(stack));
	free(stack);
}
void test_push_String_in_stack(){
	String element = "digs";
	Stack* stack = create(2);
	push(stack,&element);
	ASSERT(strcmp("digs",**(String**)getElement(stack)) == 0);
	free(stack);
}
void test_stack_push_reallocates_memory_when_size_is_exceded(){
	int _one = 1;
	int result;
	Stack* stack = create(2);
	push(stack,&_one);
	push(stack,&_one);
	push(stack,&_one);
	ASSERT(stack->length == 4);
	free(stack);
}
void test_pop_integer_from_stack(){
	int _one = 1;
	int _two = 2;
	int* result;
	Stack* stack = create(2);
	push(stack,&_one);
	push(stack,&_two);
	result = pop(stack);
	ASSERT(stack->top == 0);
    ASSERT(2==*result);
	free(stack);
}
void test_underflow_of_pop(){
	Stack* stack = create(2);
	ASSERT(pop(stack) == NULL);
	free(stack);
}
void test_top_of_integer_stack(){
	int _one = 1;
	int _two = 2;
	int result;
	Stack* stack = create(2);
	push(stack,&_one);
	push(stack,&_two);
	result = *(int*)top(stack);
	ASSERT(result == 2);
	free(stack);
}