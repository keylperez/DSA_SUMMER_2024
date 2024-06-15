#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	StackArrayList myStack;
//	initStack(&myStack);
	myStack = createStack();
	
	if(isEmpty(myStack)) printf("\nSTACK EMPTY!!\n");
	
	int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int trav;
	for(trav = 0; trav < MAX && !isFull(myStack); trav++ ){
	
		if(stack_push(&myStack, elements[trav])) printf("\nPush Success");
	}
	
	if(stack_push(&myStack, 11)) printf("\nPush Success");
	
	if(isFull(myStack)) printf("\nSTACK IS FULL!!\n");
	
	printf("\n========================================\n");
	printf("\nORIGINAL STACK:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");

	if(stack_pop(&myStack)) printf("\nPop Success\n");
	
	if(isFull(myStack)) printf("\nSTACK IS FULL!!\n");
	
	printf("\n========================================\n");
	printf("\nSTACK AFTER POP:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");
	
	StackArrayList evenStack = evenFromStack(myStack);
	if(!isEmpty(evenStack)){
		
		printf("\n========================================\n");
		printf("\nEVEN STACK:\n");
		printf("\nElements: ");
		stack_display(evenStack);
		stack_visualize(evenStack);
		printf("\n========================================\n");
		
	} else {
		printf("\nEMPTY EVEN STACK!!");
	}
	
	printf("\n========================================\n");
	printf("\nORIGINAL STACK:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");
	
	return 0;
}
