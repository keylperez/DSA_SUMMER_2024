#ifndef QUEUE_LIST
#define QUEUE_LIST

#include<stdbool.h>

#define MAX 10

typedef struct{
	int data[MAX];
	int top;
} QueueList;

void initQueue(QueueList *s);
//QueueList createQueue();

bool isEmpty(QueueList s);
bool isFull(QueueList s);

bool enqueue(QueueList *s, int elem);
bool dequeue(QueueList *s);
int peek_front(QueueList s);
int peek_rear(QueueList s);

void display(QueueList s);
void visualize(QueueList s);

//others
QueueList evenFromQueue(QueueList s);

#endif
