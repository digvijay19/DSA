#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_new_empty_priority_queue(){
	PQueue* queue = createQueue();
	ASSERT(queue->head == NULL);
	ASSERT(queue->length == 0);
	free(queue);
}
void test_create_new_node_with_data_priority_next_elementAddress(){
	int _1 = 1;
	Node* node = createNode(&_1,2);
	ASSERT(node->element == &_1);
	ASSERT(node->priority == 2);
	ASSERT(node->next == NULL);
	free(node);
}
void test_create_new_node_floating_data(){
	float element = 1.1;
	Node* node = createNode(&element,2);
	ASSERT(node->element == &element);
	ASSERT(node->priority == 2);
	ASSERT(node->next == NULL); 
	free(node);
}
void test_create_new_node_double_data(){
	double element = 1.1;
	Node* node = createNode(&element,2);
	ASSERT(node->element == &element);
	ASSERT(node->priority == 2);
	ASSERT(node->next == NULL); 
	free(node);
}
void test_create_new_node_character_data(){
	char element = 'a';
	Node* node = createNode(&element,2);
	ASSERT(node->element == &element);
	ASSERT(node->priority == 2);
	ASSERT(node->next == NULL); 
	free(node);
}
void test_create_new_node_String_data(){
	String element = "abc";
	Node* node = createNode(&element,2);
	ASSERT(node->element == &element);
	ASSERT(node->priority == 2);
	ASSERT(node->next == NULL);
	free(node);
}

void test_enqueue_in_empty_priority_queue(){
	int element = 1;
	PQueue* queue = createQueue();
	Node* one; 
	enqueue(queue, &element,1);
	one = queue->head;
	ASSERT(one->element == &element);
	ASSERT(queue->length == 1);
}
void test_enqueue_two_elements(){
	int _1 = 1;
	int _2 = 2;
	PQueue* queue = createQueue();
	Node *one,*two; 
	enqueue(queue, &_1,1);
	enqueue(queue, &_2,1);
	one = queue->head;
	ASSERT(one->element == &_1);
	two = one->next;
	ASSERT(two->element == &_2);
	ASSERT(queue->length == 2);
}
void test_enqueue_three_elements_with_different_priorities(){
	int _1 = 1;
	int _2 = 2;
	int _3 = 3;
	PQueue* queue = createQueue();
	Node *one,*two,*three; 
	enqueue(queue, &_1,1);
	enqueue(queue, &_2,1);
	enqueue(queue, &_3,2);
	one = queue->head;
	two = one->next;
	three = two->next;
	ASSERT(one->element == &_1);
	ASSERT(two->element == &_2);
	ASSERT(three->element == &_3);
	ASSERT(queue->length == 3);
}
void test_enqueue_four_elements_with_different_priorities(){
	int _1 = 1;
	int _2 = 2;
	int _3 = 3;
	int _4 = 4;
	PQueue* queue = createQueue();
	Node *one,*two,*three,*four; 
	enqueue(queue, &_1,1);
	enqueue(queue, &_2,1);
	enqueue(queue, &_3,2);
	enqueue(queue, &_4,1);
	one = queue->head;
	two = one->next;
	three = two->next;
	four = three->next;
	ASSERT(one->element == &_1);
	ASSERT(two->element == &_2);
	ASSERT(three->element == &_4);
	ASSERT(four->element == &_3);
	ASSERT(queue->length == 4);
}
void test_enqueue_next_element_with_highest_priority(){
	int _1 = 1;
	int _2 = 2;
	PQueue* queue = createQueue();
	Node *one,*two; 
	enqueue(queue, &_1,2);
	enqueue(queue, &_2,1);
	one = queue->head;
	two = one->next;
	ASSERT(one->element == &_2);
	ASSERT(two->element == &_1);
	ASSERT(queue->length == 2);
}
void test_dequeue_from_queue_of_two_elements(){
	int _1 = 1;
	int _2 = 2;
	PQueue* queue = createQueue();
	enqueue(queue, &_1,1);
	enqueue(queue, &_2,1);
	ASSERT(dequeue(queue) == &_1);
	ASSERT(queue->length == 1);
}
void test_dequeue_from_empty_queue(){
	PQueue* queue = createQueue();
	ASSERT(dequeue(queue) == NULL);
	ASSERT(queue->length == 0);
}