#include "testUtils.h"
#include "match.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_length_of_braces_should_be_even(){
	String temp = "{}";
	ASSERT(matchBraces(temp)==1);
}
void test_odd_number_of_braces_returns_false(){
	String temp = "{}{";
	ASSERT(matchBraces(temp)==0);
}
void test_incorrect_order_returns_false(){
	String temp = "{(})";
	ASSERT(matchBraces(temp)==0);
}
void test_correct_order_of_two_type_of_braces(){
	String temp = "{()}";
	ASSERT(matchBraces(temp)==1);
}
void test_correct_order_of_multiple_braces(){
	String temp = "{()}<>()(<{}>)";
	ASSERT(matchBraces(temp)==1);
}
void test_correct_order_of_multiple_braces_with_characters(){
	String temp = "{(taj)pallavi}<its>a(working)code(<{congrats}>)";
	ASSERT(matchBraces(temp)==1);
}
void test_incorrect_oreder_starting_with_closing_paranthesis(){
	String temp = "}}{}";
	ASSERT(matchBraces(temp)==0);
}