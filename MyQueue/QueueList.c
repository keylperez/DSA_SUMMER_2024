#include<stdlib.h>
#include<stdio.h>
#include "QueueList.h"

#include<stdbool.h>

#define MAX 10

typedef struct queue{
	int data[MAX];
	int next;
} *QueueList;

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
