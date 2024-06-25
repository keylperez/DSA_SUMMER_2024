#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CPUScheduling.h"

void initializeQueue(CPU *queue){
	
	queue->front = queue->rear = NULL;
}

CPU createQueue(){
	
	CPU newQueue;
	newQueue.front = newQueue.rear = NULL;

	return newQueue;
}

bool isEmpty(CPU queue){
	return queue.front == NULL && queue.rear == NULL;
}

NodePtr processFront(CPU queue){
	return !isEmpty(queue) ? queue.front : NULL;
}

NodePtr processRear(CPU queue){
	return !isEmpty(queue) ? queue.rear : NULL;
}

ProcessNode fillProcess(char name, int bt, int at){
	
	ProcessNode *newNode = (ProcessNode*) malloc(sizeof(ProcessNode));
	
	if(newNode != NULL){
			
		newNode->processName = name;
		newNode->burstTime = bt;
		newNode->arrivalTime = at;
		
		if(at == 0){
			newNode->completionTime = bt;
		}
		newNode->waitingTime = 0;
		newNode->turnAroundTime = 0;
	} else {
		printf("\nError allocating memory");
	}
	
	return *newNode;
}

bool enqueueProcess(CPU *queue, ProcessNode p){
	
	bool enqueueMsg = false;
	NodePtr newNode;
	
	CPU tempQueue = createQueue();
	newNode = (NodePtr) malloc(sizeof(Node));
	
	if(newNode != NULL){
		
		newNode->elem = p;
		newNode->next = NULL;
		
		if(isEmpty(*queue)){
			queue->front = queue->rear = newNode;
		} else {
			
			NodePtr comp = processRear(*queue);
			
			if(p.arrivalTime >= comp->elem.arrivalTime || queue->rear == NULL){
				
				queue->rear->next = newNode;
				queue->rear = newNode;
			} else {
				
				// recurssion to sort enQeueud nodes
				while(!isEmpty(*queue)){
					if(!enqueueProcess(&tempQueue, processFront(*queue)->elem)) printf("\nError enqueueing to tempQueue at enqueue function");
					if(!dequeueProcess(queue)) printf("\nError dequeuing queue at enqueue function");
				}
				
				if(!enqueueProcess(queue, newNode->elem)) printf("\nError enqueueing to queue after dequeue in enqueue function");			
				
				while(!isEmpty(tempQueue)){
					if(!enqueueProcess(queue, processFront(tempQueue)->elem)) printf("\nError enqueueing to queue in enqueue function");
					if(!dequeueProcess(&tempQueue)) printf("\nError dequeuing tempQueue in enqueue function");
				}
			}
		}
		
		enqueueMsg = true;
	} else {
		printf("\nError allocating memory!\n");
	}
	
	return enqueueMsg;
}

bool dequeueProcess(CPU *queue){
		
	bool dequeueMsg = false;
	
	if(!isEmpty(*queue)){
			
		NodePtr delPtr;
		delPtr = queue->front;
		queue->front = delPtr->next;
		
		free(delPtr);
		if(queue->front == NULL) queue->rear = NULL;
		
		dequeueMsg = true;		
		
	} else {
		printf("\nUnable to deQueue emptyQueue!");
	}
	
	return dequeueMsg;
}


int computeTAT(ProcessNode node){

//	Turn Around Time = Completion Time – Arrival Time
	return node.completionTime - node.arrivalTime;
}

int computeWT(ProcessNode node){

//	Waiting Time = Turn Around Time – Burst Time
	return node.turnAroundTime - node.burstTime;
}

void displayProcesses(CPU queue){
	
	CPU tempQueue = createQueue();
	CPU sortQueue = createQueue();
	
	if(!isEmpty(queue)){
				
		int completion = 0, count = 0, i, averageTAT = 0, averageWT = 0;
				
		printf("\n\nDISPLAY:\n%-14s%7s%7s%7s%7s%7s", "Process", "BT", "AT", "CT", "TAT", "WT");
		
		printf("\n");
		for(i = 0; i < 50; i++){
			printf("_");
		}
		
		while(!isEmpty(queue)){
			
			NodePtr pNode = processFront(queue);
			if(!enqueueProcess(&tempQueue, pNode->elem)) printf("\nError enqueuing to tempQueue");
			if(!dequeueProcess(&queue)) printf("\nError dequeuing from queue");
		}

		while(!isEmpty(tempQueue)){

			NodePtr tn = processFront(tempQueue);
			
			completion += tn->elem.burstTime;
			tn->elem.completionTime = completion;
			tn->elem.turnAroundTime = computeTAT(tn->elem);
			tn->elem.waitingTime = computeWT(tn->elem);
			averageTAT += tn->elem.turnAroundTime;
			averageWT += tn->elem.waitingTime;
			
			printf("\n%-14c%7d%7d%7d%7d%7d", tn->elem.processName, tn->elem.burstTime, tn->elem.arrivalTime, tn->elem.completionTime, tn->elem.turnAroundTime, tn->elem.waitingTime);
			if(!dequeueProcess(&tempQueue)) printf("\nError Dequeuing tempQueue");
			count++;
		}
		
		// display aesthetic
		printf("\n");
		for(i = 0; i < 50; i++){
			printf("_");
		}
		
		printf("\n%s%35.2f%7.2f\n\ncount: %d", "Average:", (float)averageTAT/count, (float)averageWT/count, count);
		
	} else {
		printf("\nQueue is empty!!");
	}
	
}

void visualizeProcesses(CPU queue){
	
	if(!isEmpty(queue)){
			
		NodePtr trav;
		
		printf("\n\nVISUALIZATION:\n%-14s%7s%7s", "Process", "BT", "AT");
		for(trav = queue.front; trav != NULL; trav = trav->next){
			printf("\n%-14c%7d%7d", trav->elem.processName, trav->elem.burstTime, trav->elem.arrivalTime);
		}
	} else {
		printf("\nList is empty!!");
	}
}
