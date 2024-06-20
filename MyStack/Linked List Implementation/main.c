#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	Stack myStack;
	initStack(&myStack);
//	myStack = createStack();
	
	if(isEmpty(myStack)) printf("\nSTACK EMPTY!!\n");
	
	int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int trav;
	
    for(trav = 0; trav < sizeof(elements)/sizeof(elements[0]); trav++){
    
        if(stack_push(&myStack, elements[trav])) printf("\nPush Success");
    }
	
	if(stack_push(&myStack, 11)) printf("\nPush Success");
	
	printf("\nStack peek: %d", stack_peek(myStack));
	
	printf("\n========================================\n");
	printf("\nORIGINAL STACK:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");

	if(stack_pop(&myStack)) printf("\nPop Success\n");
	
	printf("\n========================================\n");
	printf("\nSTACK AFTER POP:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");	
	
	Stack evenStack = evenFromStack(myStack);
	

	printf("\n========================================\n");
	printf("\nEVEN STACK:\n");
	stack_display(evenStack);
	stack_visualize(evenStack);
	printf("\n========================================\n");
	
	
	printf("\n========================================\n");
	printf("\nORIGINAL STACK:\n");
	printf("\nElements: ");
	stack_display(myStack);
	stack_visualize(myStack);
	printf("\n========================================\n");
		
	return 0;
}
