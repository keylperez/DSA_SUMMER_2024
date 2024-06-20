#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularArray.h"

void initQueue(CircularArray *q){
	q->front = q->rear = -1;
}

CircularArray createQueue(){
	CircularArray newQueue;
	
	newQueue.front = newQueue.rear = -1;
	
	return newQueue;
}

bool Enqueue(CircularArray *q, int elem){
	
	bool enqueueMsg = false;
	
	if(!isFull(*q)){
		q->rear = ++q->rear%MAX;
		q->data[q->rear] = elem;
		if(q->front == -1) q->front = 0;
		enqueueMsg = true;
	
	} else {
		printf("\nQueue is full!!\n");
	}
	
	return enqueueMsg;
}

int Front(CircularArray q){
	return q.data[q.front];
}

bool Dequeue(CircularArray *q){
	
	bool dequeueMsg = false;
	
	if(!isEmpty(*q)){
		
		if(q->front == q->rear) {
		
			q->front = q->rear = -1;
		} else {
			
				
			q->front = ++q->front%MAX;
			
		}
		dequeueMsg = true;
	} else {
		printf("\nQueue is empty!!");
	}
	
	return dequeueMsg;
}

int Rear(CircularArray q){
	return q.data[q.rear];
}

bool isEmpty(CircularArray q){
	return q.front == -1;
}

bool isFull(CircularArray q){
	
	return ((q.rear + 2) % MAX == q.front);
}

void displayQueue(CircularArray q){
	
	if(isEmpty(q)) printf("\nQueue is empty!!");
	while(!isEmpty(q)){
		
		printf("%d ", q.data[q.front]);
		if(!Dequeue(&q)) printf("\nError dequeuing paramter queue");
	}
}

void visualizeQueue(CircularArray q){
	if(!isEmpty(q)){
		printf("\n%-7s %-7s %-7s", "Element", "Index", "Front&Rear");
		int trav;
		for(trav = 0; trav < MAX; trav++){
			printf("\n%-7d %-7d ", q.data[trav], trav);
			if(trav == q.front) printf("%-7s", "FRONT");
			if(trav == q.rear) printf("%-7s", "REAR");
		}
		printf("\n---------------------\n");
	} else {
		printf("\nQueue is empty!!\n");	
	}
}

CircularArray evenFromQueue(CircularArray q){
	
	CircularArray evenQueue = createQueue();
	
	if(!isEmpty(q)){
		
		while(!isEmpty(q)){
			if(q.data[q.front]%2 == 0){
				if(!Enqueue(&evenQueue, q.data[q.front])) printf("\nError enqueuing to evenQueue");
			}
			if(!Dequeue(&q)) printf("\nError deququing from parameter queue");
		}
	} else {
		printf("\nQueue is empty!!");
	}
	
	return evenQueue;
}

