#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY
#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int front;
	int rear;
} CircularArray;

void initQueue(CircularArray *q);
CircularArray createQueue();

bool Enqueue(CircularArray *q, int elem);
int Front(CircularArray q);
bool Dequeue(CircularArray *q);
int Rear(CircularArray q);

bool isEmpty(CircularArray q);
bool isFull(CircularArray q);

void displayQueue(CircularArray q);
void visualizeQueue(CircularArray q);

CircularArray evenFromQueue(CircularArray q);

#endif
