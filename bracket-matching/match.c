#include "match.h"
#include <String.h>
#include <stdlib.h>

int findIndex(char braces[], char element){
	int i;
	for(i=0;i<3;i++)
		if(braces[i]==element)	return i;
	return -1;
};
int totalbraces(char data[]){
	int i,count=0;
	char allBraces[] = {'{','}','[',']','(',')','<','>'};
	for(i=0;i<strlen(data);i++)
		if(findIndex(allBraces, data[i])!=-1)	count++;
	return count;
}
charStack* createStack(int length){
	charStack *temp = calloc(1,sizeof(charStack));
	temp->braces = calloc(length,sizeof(char));
	temp->length = length;
	temp->top = -1;
	return temp;
}
void push(charStack *stack,char *element){
	char *newPosition = stack->braces+(stack->top+1);
	memcpy (newPosition, element, sizeof(char));
	stack->top++;
}
void pop(charStack *stack){
	stack->top--;
}
int matchBraces(String data){
	int i,openingIndex,closingIndex,stackElementOpeningIndex,top;
	char opening[] = {'{','[','(','<'};
	char closing[] = {'}',']',')','>'};

	charStack *stack = createStack(totalbraces(data));
	for(i=0;i<strlen(data);i++){
		openingIndex = findIndex(opening,data[i]);
		closingIndex = findIndex(closing,data[i]);
		if( openingIndex != -1 || (closingIndex != -1 && stack->top == -1))
			push(stack,&data[i]);
		stackElementOpeningIndex = findIndex(opening, stack->braces[stack->top]);
		if( closingIndex == stackElementOpeningIndex && closingIndex != -1)
			pop(stack);
	}
	top = stack->top;
	free(stack);
	return (top==-1)?1:0;
}