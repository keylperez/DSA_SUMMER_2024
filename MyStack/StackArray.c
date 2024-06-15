#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList newStack;
	newStack.top = -1;
	
	return newStack;
}

bool isEmpty(StackArrayList s){
	return s.top == -1;
}
bool isFull(StackArrayList s){	
	return s.top >= (MAX - 1);
}

bool stack_push(StackArrayList *s, int elem){
	
	bool pushMsg = false;
	
	if(!isFull(*s)){
		
		s->data[++s->top] = elem;
		pushMsg = true;
	} else {
		printf("\nStack is full!\n");
	}
	
	return pushMsg;
}

bool stack_pop(StackArrayList *s){
	
	bool popMsg = false;
	
	if(!isEmpty(*s)){
		
		s->top--;
		popMsg = true;
	} else {
		printf("\nStack is empty!\n");
	}
	
	return popMsg;	
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void stack_display(StackArrayList s){
	StackArrayList tempStack;
	initStack(&tempStack);
	
	while(!isEmpty(s)){
		
		if(stack_push(&tempStack, stack_peek(s))){
			
			if(!stack_pop(&s)) printf("\nError Pop\n"); 
		} else {
			
			printf("\nError Push!\n");
		}
		
	}	
	

	while(!isEmpty(tempStack)){
		
		if(stack_push(&s, stack_peek(tempStack))){
			
			
			printf("%d ", stack_peek(tempStack));
			if(!stack_pop(&tempStack)) printf("\nError Pop\n"); 
		} else {
			
			printf("\nError Push!\n");
		}
		
	}
	
}

void stack_visualize(StackArrayList s){

	if(!isEmpty(s)){
		printf("\n\nElement\tIndex\tTop");
		int trav;
		for(trav = 0; trav < MAX && trav <= s.top; trav++){
			printf("\n%d\t%d\t", s.data[trav], trav);
			if(trav == s.top) printf("TOP");
		}
		printf("\n---------------------\n");
	} else {
		printf("\nEmpty Stack\n");	
	}
	
}

//others
StackArrayList evenFromStack(StackArrayList s){
	StackArrayList evenStack, tempStack;
	initStack(&evenStack);
	initStack(&tempStack);
	
//	Traverse Implementatino
//	if(!isEmpty(s)){
//		int trav;
//		for(trav = 0; trav < MAX && trav <= s.top; trav++){
//			if(s.data[trav]%2 == 0) stack_push(&evenStack, s.data[trav]);
//		}
//	} else {
//		printf("\nEmpty Stack\n");	
//	}
	
//	Push&Pop Implementation
	while(!isEmpty(s)){
		
		if(stack_push(&tempStack, stack_peek(s))){
			
			if(!stack_pop(&s)) printf("\nError Pop\n"); 
		} else {
			
			printf("\nError Push!\n");
		}
		
	}	
	

	while(!isEmpty(tempStack)){
		
		if(stack_push(&s, stack_peek(tempStack))){
			
			
			if(stack_peek(tempStack)%2==0) stack_push(&evenStack, stack_peek(tempStack));
			if(!stack_pop(&tempStack)) printf("\nError Pop\n"); 
		} else {
			
			printf("\nError Push!\n");
		}
		
	}
	
	return evenStack;
}
