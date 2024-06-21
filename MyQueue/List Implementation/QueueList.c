#include<stdlib.h>
#include<stdio.h>
#include "QueueList.h"

#include<stdbool.h>

void initQueue(Queue *q){
	q->front = q->rear = NULL;
}
//Queue createQueue();

bool isEmpty(Queue q){
	return (q.front == NULL && q.rear == NULL);
}

bool enqueue(Queue *q, int elem){
	
	bool enqueueMsg = false;
	NodePtr temp;
	temp = (NodePtr) malloc(sizeof(Node));
	
	if(temp != NULL){
		
		temp->data = elem;
		temp->next = NULL;
		
		if(isEmpty(*q)){
			
			q->front = q->rear = temp;
			
		} else {
		
			q->rear->next = temp;
			q->rear = temp;
			
		}
		enqueueMsg = true;
		
	} else {
		
		printf("\nError allocating memory!\n");
		
	}
	
	return enqueueMsg;
}

bool dequeue(Queue *q){
	
	bool dequeueMsg = false;
	
	if(!isEmpty(*q)){
		
		NodePtr newNode, temp;
		
		newNode = temp =  q->front;
		q->front = newNode->next;
		
		free(temp);
		
		dequeueMsg = true;
	} else {
		printf("\nEmpty Queue!\n");
	}
	
	return dequeueMsg;
}

int peek_front(Queue q){
	return q.front->data;
}
int peek_rear(Queue q){
	return q.rear->data;
}

void display(Queue q){
	NodePtr trav;
	for(trav = q.front; trav != NULL; trav = trav->next){
		printf("\nnode: %d", trav->data);
	}
	printf("\n\n");
}

//others
Queue evenFromQueue(Queue q){
	Queue newQueue;
	NodePtr trav;
	
	initQueue(&newQueue);
	
	for(trav = q.front; trav != NULL; trav = trav->next){
		
		if(trav->data%2 == 0){
			
			enqueue(&newQueue, trav->data) ? printf("\nExtracted Even") : printf("\nError Extraction");
		}
	}
	
	printf("\n\n");
	
	return newQueue;
}
