#ifndef STACK
#define STACK

#include<stdbool.h>

typedef struct node{
	char data;
	struct node *next;
} stackList, *stackListPtr;

typedef struct{
	stackListPtr top;
}Stack;

void initStack(Stack *s);
Stack createStack();

bool stack_push(Stack *s, char elem);
bool stack_pop(Stack *s);
char stack_peek(Stack s);
bool isEmpty(Stack s);

void stack_display(Stack s);
void stack_visualize(Stack s);

//create a function that would get all even numbers and return as new stack removing from the old stack
Stack evenFromStack(Stack s);

#endif
