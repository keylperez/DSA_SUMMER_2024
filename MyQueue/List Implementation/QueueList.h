#ifndef QUEUE_LIST
#define QUEUE_LIST

#include<stdbool.h>

typedef struct node{
	int data;
	struct node* next;
} Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
} Queue; 

void initQueue(Queue *q);
//Queue createQueue();

bool isEmpty(Queue q);

bool enqueue(Queue *q, int elem);
bool dequeue(Queue *q);
int peek_front(Queue q);
int peek_rear(Queue q);

void display(Queue q);

//others
Queue evenFromQueue(Queue s);

#endif
