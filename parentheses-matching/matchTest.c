#include "testUtils.h"
#include "match.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_length_of_braces_should_be_even(){
	String temp = "{}";
	ASSERT(matchBraces(temp)==1);
}
void test_odd_number_of_braces(){
	String temp = "{}{";
	ASSERT(matchBraces(temp)==0);
}
void test_incorrect_order(){
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
	String temp = "{abc}";
	ASSERT(matchBraces(temp)==1);
}
void test_incorrect_order_starting_with_closing_paranthesis(){
	String temp = "}{";
	ASSERT(matchBraces(temp)==0);
}
void test_incorrect_order_with_characters(){
	String temp = "a}b{c";
	ASSERT(matchBraces(temp)==0);
}
void test_correct_order_with_all_types_of_braces(){
	String temp = "{}()[]<>";
	ASSERT(matchBraces(temp)==1);
}
void test_correct_order_with_all_braces_included_in_each_other(){
	String temp = "{([<>])}";
	ASSERT(matchBraces(temp)==1);
}
void test_correct_order_for_complex_code(){
	String temp = "{abc {a} (b) {c} [hello()] <h1>}";
	ASSERT(matchBraces(temp)==1);
}