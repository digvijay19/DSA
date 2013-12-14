#include "testUtils.h"
#include "isort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct{
	int ID;
	int balance;
} Account;

int compareIntegers(void* a,void* b){
	return (*(int*)a - *(int*)b);
}
int compareChars(void* a,void* b){
	return (*(char*)a - *(char*)b);
}
int compareFloats(void* a,void* b){
	if(*(float*)a - *(float*)b < 0)
		return -1;
	return 1;
}
int compareBalance(void* a,void* b){
	Account *first = (Account*)a;
	Account *second = (Account*)b;
	return (first->balance - second->balance);
}
int areEqual(void* numbers,void* expected,int lenght,int typeSize){
	return 0 == memcmp(expected,numbers,lenght*typeSize);
}

void test_isort_for_5_integers(){
	int numbers[] = {2,1,4,5,3};
	int expected[] = {1,2,3,4,5};
	isort( numbers,5,sizeof(int),compareIntegers);
	ASSERT(areEqual(numbers,expected,5,4) != 0);
}
void test_isort_best_case_for_5_integers(){
	int numbers[] = {1,2,3,4,5};
	int expected[] = {1,2,3,4,5};
	isort( numbers,5,sizeof(int),compareIntegers);
	ASSERT(areEqual(numbers,expected,5,4) != 0);
}
void test_isort_worst_case_for_5_integers(){
	int numbers[] = {5,4,3,2,1};
	int expected[] = {1,2,3,4,5};
	isort( numbers,5,sizeof(int),compareIntegers);
	ASSERT(areEqual(numbers,expected,5,4) != 0);
}
void test_isort_for_bank_account_by_balance(){
	int i;
	Account actual[] = {{2,20},{1,10},{3,30}};
	Account expected[] = {{1,10},{2,20},{3,10}};
	isort( actual,3,sizeof(Account),compareBalance);
	ASSERT(actual[0].ID == 1 && actual[0].balance == 10);
	ASSERT(actual[1].ID == 2 && actual[1].balance == 20);
	ASSERT(actual[2].ID == 3 && actual[2].balance == 30);
}
void test_isort_for_bank_account_by_balance_best_case(){
	int i;
	Account actual[] = {{1,10},{2,20},{3,30}};
	Account expected[] = {{1,10},{2,20},{3,30}};
	isort( actual,3,sizeof(Account),compareBalance);
	ASSERT(actual[0].ID == 1 && actual[0].balance == 10);
	ASSERT(actual[1].ID == 2 && actual[1].balance == 20);
	ASSERT(actual[2].ID == 3 && actual[2].balance == 30);
}
void test_isort_for_bank_account_by_balance_worst_case(){
	int i;
	Account actual[] = {{4,40},{3,30},{2,20},{1,10}};
	Account expected[] = {{1,10},{2,20},{3,30},{4,40}};
	isort( actual,4,sizeof(Account),compareBalance);
	ASSERT(actual[0].ID == 1 && actual[0].balance == 10);
	ASSERT(actual[1].ID == 2 && actual[1].balance == 20);
	ASSERT(actual[2].ID == 3 && actual[2].balance == 30);
	ASSERT(actual[3].ID == 4 && actual[3].balance == 40);
}
void test_isort_with_float_values(){
	float numbers[] = {1.2,1.1,0.0,3.3,4.4};
	float expected[] = {0.0,1.1,1.2,3.3,4.4};
	isort( numbers,5,sizeof(float),compareFloats);
	ASSERT(areEqual(numbers,expected,5,sizeof(float)) != 0);
}
void test_isort_with_float_values_best_case(){
	float numbers[] = {0.0,1.1,1.2,3.3,4.4};
	float expected[] = {0.0,1.1,1.2,3.3,4.4};
	isort( numbers,5,sizeof(float),compareFloats);
	ASSERT(areEqual(numbers,expected,5,sizeof(float)) != 0);
}
void test_isort_with_float_values_worst_case(){
	float numbers[] = {4.4,3.3,1.2,1.1,0.0};
	float expected[] = {0.0,1.1,1.2,3.3,4.4};
	isort( numbers,5,sizeof(float),compareFloats);
	ASSERT(areEqual(numbers,expected,5,sizeof(float)) != 0);
}
void test_isort_for_caharacters(){
	char characters[] = {'b','a','d','e','c'};
	char expected[] = {'a','b','c','d','e'};
	isort( characters,5,sizeof(char),compareChars);
	ASSERT(areEqual(characters,expected,5,sizeof(char)) != 0);
}
void test_isort_for_caharacters_best_case(){
	char characters[] = {'a','b','c','d','e'};
	char expected[] = {'a','b','c','d','e'};
	isort( characters,5,sizeof(char),compareChars);
	ASSERT(areEqual(characters,expected,5,sizeof(char)) != 0);
}
void test_isort_for_caharacters_worst_case(){
	char characters[] = {'e','d','c','b','a'};
	char expected[] = {'a','b','c','d','e'};
	isort( characters,5,sizeof(char),compareChars);
	ASSERT(areEqual(characters,expected,5,sizeof(char)) != 0);
}