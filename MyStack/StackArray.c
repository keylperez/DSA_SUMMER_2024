#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
}

bool isEmpty(StackArrayList s){
	return s.top == -1;
}
bool isFull(StackArrayList s){	
	return s.top >= MAX;
}

bool stack_push(StackArrayList *s, int elem){
	
	bool pushMsg = false;
	
	bool stackFull = isFull(*s);
	
	if(!stackFull){
		
		s->data[++s->top] = elem;
//		(s->top)++;
		pushMsg = true;
	}
	
	return pushMsg;
}

bool stack_pop(StackArrayList *s){
	
	bool popMsg = false;
	
	bool stackEmpty = isEmpty(*s);
	
	if(!stackEmpty){
		
//		int top = s->top;
		s->data[--s->top] = -1;
//		(s->top)--;
		popMsg = true;
	}	
	
	return popMsg;	
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void stack_display(StackArrayList s){
	StackArrayList tempStack = createStack();
	
}

void stack_visualize(StackArrayList s){

	printf("Element\tIndex\tTop");
}

//others
//StackArrayList evenFromStack(StackArrayList s);
