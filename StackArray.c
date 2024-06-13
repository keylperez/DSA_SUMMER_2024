#include <stdio.h>
#include <stdlib.h>
#include <stdboo.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	*s->top = -1;
}

StackArrayList createStack(){
	StackArrayList s;
	initStack(&s);
	return s;
}

bool isEmpty(StackArrayList s){
	return s.top == -1 ? true : false;
}
bool isFull(StackArrayList s){	
	return s.top >== (sizeof(s.data/4) - 1) ? true : false;
}

bool stack_push(StackArrayList *s, int elem){
	
	bool pushMsg = false;
	
	bool stackFull = isFull(s);
	
	if(stackFull == false)){
		
		*s->data[s.top] = elem;
		*s->top++;
		pushMsg = true;
	}
	
	return pushMsg;
}

bool stack_pop(StackArrayList *s){
	
	bool popMsg = false;
	
	bool stackEmpty = isEmpty(s);
	
	if(stackEmpty == false){
		
		*s->data[s.top] = NULL;
		*s->top--;
		popMsg = true;
	}	
	
	return popMsg;	
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
		
}

void visualize(StackArrayList s);

//others
StackArrayList evenFromStack(StackArrayList s);
