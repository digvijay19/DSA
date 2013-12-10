#include "testUtils.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack *integerStack;
Stack *floatStack;
Stack *doubleStack;
Stack *charStack;
Stack *stringStack;

int areEqual(Stack a, Stack b){
	int result = a.top == b.top && a.maxElements == b.maxElements && a.sizeOfElement == b.sizeOfElement;
	if(!result) return result;
	return 0 == memcmp(a.array,b.array,a.maxElements*a.sizeOfElement);
};

void test_create_stack_of_two_integers(){
	int two_zeroes[] = {0,0};
	Stack b = {two_zeroes,-1,4,2};
	integerStack = create(sizeof(int),2);
	ASSERT(areEqual(*integerStack,b));
	free(integerStack);
}
void test_create_stack_of_two_floats(){
	float two_zeroes[] = {0,0};
	Stack b = {two_zeroes,-1,sizeof(float),2};
	floatStack = create(sizeof(float),2);
	ASSERT(areEqual(*floatStack,b));
	free(floatStack);
}
void test_create_stack_of_two_doubles(){
	double two_zeroes[] = {0,0};
	Stack b = {two_zeroes,-1,sizeof(double),2};
	doubleStack = create(sizeof(double),2);
	ASSERT(areEqual(*doubleStack,b));
	free(doubleStack);
}
void test_create_stack_of_two_chars(){
	char two_chars[] = {'\0','\0'};
	Stack b = {two_chars,-1,sizeof(char),2};
	charStack = create(sizeof(char),2);
	ASSERT(areEqual(*charStack,b));
	free(charStack);
}
void test_create_stack_of_two_Strings(){
	String two_zeroes[] = {"\0","\0"};
	Stack b = {two_zeroes,-1,sizeof(String),2};
	stringStack = create(sizeof(String),2);
	ASSERT(areEqual(*stringStack,b));
	free(stringStack);
}
void test_push_integer_in_stack(){
	int expected[] = {1,0};
	int element = 1;
	Stack b = {expected,0,sizeof(int),2};
	integerStack = create(sizeof(int),2);
	push(integerStack,&element);
	ASSERT(areEqual(*integerStack,b));
	free(integerStack);
}
void test_overflow_of_stack_when_pushed(){
	int expected[] = {1,1};
	int element = 1;
	int result;
	Stack b = {expected,1,sizeof(int),2};
	integerStack = create(sizeof(int),2);
	push(integerStack,&element);
	push(integerStack,&element);
	result=push(integerStack,&element);
	ASSERT(result==0 && areEqual(*integerStack,b));
	free(integerStack);
}
void test_push_float_in_stack(){
	float expected[] = {1.1,0.0,0.0,0.0};
	float element = 1.1;
	Stack b = {expected,0,sizeof(float),4};
	floatStack = create(sizeof(float),4);
	push(floatStack,&element);
	ASSERT(areEqual(*floatStack,b));
	free(floatStack);
}
void test_push_float_in_stack_two_times(){
	float expected[] = {1.1,1.1,0.0,0.0};
	float element = 1.1;
	Stack b = {expected,1,sizeof(float),4};
	floatStack = create(sizeof(float),4);
	push(floatStack,&element);
	push(floatStack,&element);
	ASSERT(areEqual(*floatStack,b));
	free(floatStack);
}
void test_push_double_in_stack(){
	double expected[] = {1.1,0.0,0.0,0.0};
	double element = 1.1;
	Stack b = {expected,0,sizeof(double),4};
	doubleStack = create(sizeof(double),4);
	push(doubleStack,&element);
	ASSERT(areEqual(*doubleStack,b));
	free(doubleStack);
}
void test_push_char_in_stack(){
	char expected[] = {'a','\0'};
	char element = 'a';
	Stack b = {expected,0,sizeof(char),2};
	charStack = create(sizeof(char),2);
	push(charStack,&element);
	ASSERT(areEqual(*charStack,b));
	free(charStack);
}
void test_push_String_in_stack(){
	String expected[] = {"abc","\0"};
	String element = "abc";
	Stack b = {expected,0,sizeof(String),2};
	stringStack = create(sizeof(String),2);
	push(stringStack,&element);
	ASSERT(areEqual(*stringStack,b));
	free(stringStack);
}
void test_pop_integer_from_stack(){
	int expected[] = {2,0};
	int _one = 1;
	int _two = 2;
	Stack b = {expected,0,sizeof(int),2};
	integerStack = create(sizeof(int),2);
	push(integerStack,&_one);
	pop(integerStack);
	push(integerStack,&_two);
	ASSERT(areEqual(*integerStack,b));
	free(integerStack);
}
void test_underflow_of_pop(){
	integerStack = create(sizeof(int),2);
	ASSERT(pop(integerStack) == NULL);
	free(integerStack);
}
void test_pop_float_from_stack(){
	float expected[] = {1.0,0.0};
	float _one = 1.0;
	Stack b = {expected,-1,sizeof(float),2};
	floatStack = create(sizeof(float),2);
	push(floatStack,&_one);
	pop(floatStack);
	ASSERT(areEqual(*floatStack,b));
	free(floatStack);
}
void test_pop_double_from_stack(){
	double expected[] = {1.0,0.0};
	double _one = 1.0;
	Stack b = {expected,-1,sizeof(double),2};
	doubleStack = create(sizeof(double),2);
	push(doubleStack,&_one);
	pop(doubleStack);
	ASSERT(areEqual(*doubleStack,b));
	free(doubleStack);
}
void test_pop_char_from_stack(){
	char expected[] = {'a','\0'};
	char _a = 'a';
	Stack b = {expected,-1,sizeof(char),2};
	charStack = create(sizeof(char),2);
	push(charStack,&_a);
	pop(charStack);
	ASSERT(areEqual(*charStack,b));
	free(charStack);
}
void test_pop_String_from_stack(){
	String expected[] = {"abc","\0"};
	String _name = "abc";
	Stack b = {expected,-1,sizeof(String),2};
	stringStack = create(sizeof(String),2);
	push(stringStack,&_name);
	pop(stringStack);
	ASSERT(areEqual(*stringStack,b));
	free(stringStack);
}
void test_top_of_integer_stack(){
	int _one = 1;
	int _two = 2;
	int result;
	integerStack = create(sizeof(int),2);
	push(integerStack,&_one);
	push(integerStack,&_two);
	result = *(int*)top(integerStack);
	ASSERT(result == 2);
	free(integerStack);
}
void test_top_of_float_stack(){
	float _one = 1.0;
	float result;
	floatStack = create(sizeof(float),4);
	push(floatStack,&_one);
	result = *(float*)top(floatStack);
	ASSERT(result == 1);
	free(floatStack);
}
void test_top_of_double_stack(){
	double _one = 1.0;
	double result;
	doubleStack = create(sizeof(double),4);
	push(doubleStack,&_one);
	result = *(double*)top(doubleStack);
	ASSERT(result == 1);
	free(doubleStack);
}
void test_top_of_char_stack(){
	char _a = 'a';
	char result;
	charStack = create(sizeof(char),4);
	push(charStack,&_a);
	result = *(char*)top(charStack);
	ASSERT(result == 'a');
	free(charStack);
}
void test_top_of_String_stack(){
	String name = "abc";
	stringStack = create(sizeof(String),4);
	push(stringStack,name);
	ASSERT(strcmp("abc",*(String*)top(stringStack))==0);
	free(stringStack);
}