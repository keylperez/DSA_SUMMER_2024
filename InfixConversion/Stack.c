#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

void initStack(Stack *s){
	s->top = NULL;
}

Stack createStack(){

	Stack newStack;
	newStack.top = NULL;
	
	return newStack;
}

bool isEmpty(Stack s){
	return s.top == NULL ? true : false;
}

bool stack_push(Stack *s, char elem){
	
	bool pushMsg = false;

	stackListPtr newNode;
	newNode = (stackList *) malloc(sizeof(stackList));
	
	if(newNode){
	
		newNode->data = elem;
		newNode->next = s->top;
		
		s->top = newNode;
		
		pushMsg = true;
	} else {
		printf("/Error allocation");
	}
	
	return pushMsg;
	
}

bool stack_pop(Stack *s){
	
	bool popMsg = false;
	
	if(!isEmpty(*s)){
			
		stackListPtr temp;
		
		temp = s->top;
		
		s->top = s->top->next;
		
		free(temp);
		
		popMsg = true;

	} else {
		printf("\nStack is empty, nothing to pop\n");
	}
	
	return popMsg;
}

char stack_peek(Stack s){
	return s.top->data;
}

void stack_display(Stack s){
	
	if(!isEmpty(s)){
				
		Stack tempStack;
		initStack(&tempStack);
		
	
		while(!isEmpty(s)){
			if (stack_push(&tempStack, stack_peek(s))){
	
				if(!stack_pop(&s)) printf("\nError popping stack\n");
						
			} else {
				printf("\nError pushing to tempStack\n");
			}
			
		}
		
		printf("\nStack: ");
		while(!isEmpty(tempStack)){
			if(stack_push(&s, stack_peek(tempStack))){
				
				printf("%c ", stack_peek(tempStack));
				if(!stack_pop(&tempStack)) printf("\nError popping from tempStack");
			} else {
				printf("\nError pushing to stack\n");
			}
		}
	} else {
		printf("\nEMPTY STACK. Nothing to display");
	}
	
}

void stack_visualize(Stack s){
	
	
	if(!isEmpty(s)){
		
		stackListPtr trav;
		
		printf("\n\nElement\tTop");
		
		for(trav = s.top; trav != NULL; trav = trav->next){

			printf("\n%c\t", trav->data);
			if(trav == s.top) printf("TOP");
		}
		printf("\n----------------------------\n");
	} else {
		printf("\nEMPTY STACK!!");
	}
}


