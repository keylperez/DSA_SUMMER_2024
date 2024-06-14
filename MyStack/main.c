#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	StackArrayList myStack;
	initStack(&myStack);
	
	stack_push(&myStack, 1);
	stack_push(&myStack, 2);
	stack_push(&myStack, 3);
	stack_push(&myStack, 4);
	stack_push(&myStack, 5);
	stack_push(&myStack, 6);
	stack_push(&myStack, 7);
	stack_push(&myStack, 8);
	stack_push(&myStack, 9);
	stack_push(&myStack, 10);
	
	isFull(myStack) ? printf("\nStack is Full") : printf("\nStack not Full");
	
	int stackPeek;
	
	stackPeek = stack_peek(myStack);
	printf("\nPeek of Stack: %d", stackPeek);
	
	stack_pop(&myStack);
	
	isFull(myStack) ? printf("\nStack is Full") : printf("\nStack not Full");
	
	stackPeek = stack_peek(myStack);
	printf("\nPeek of Stack: %d", stackPeek);
	
	return 0;
}
