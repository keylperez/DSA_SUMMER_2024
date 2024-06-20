#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CircularArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
//	printf("%d\n", 12%11);
	
	CircularArray queue;
	initQueue(&queue);
	
	int dataList[] = {19, 2, 1, 4, 25, 6, 17, 8, 99, 10, 11, 12};
	int trav;
	
	if(isEmpty(queue)) printf("Queue is empty!!\n");
	
	printf("\nFront: %d\nRear: %d\n", Front(queue), Rear(queue));
	
	for(trav = 0; trav < sizeof(dataList)/sizeof(int) && !isFull(queue); trav++){
		Enqueue(&queue, dataList[trav]) ? printf("\nEnqueue Success: %d", dataList[trav]) : printf("\nError Queue: %d", dataList[trav]);
	}
	
	printf("\nFront: %d\nRear: %d\n", Front(queue), Rear(queue));
	isEmpty(queue) ? printf("\nQueue is empty!!\n") : printf("\nQueue has space\n");
	
	
	Enqueue(&queue, 6) ? printf("\nEnqueue Success: %d", 6) : printf("\nError Queue: %d", 6);
	
//	printf("\nFront: %d\nRear: %d\n", Front(queue), Rear(queue));
	
	printf("\nVisualize:");
	visualizeQueue(queue);
	
	displayQueue(queue);
	
	if(!Dequeue(&queue)) printf("\nError dequeuing main queue");
	
	printf("\nFront: %d\nRear: %d\n", Front(queue), Rear(queue));
	
	visualizeQueue(queue);
	
	displayQueue(queue);
	
	printf("\n\n\n\n============================\nEven from Queue\n");
	CircularArray evenQueue = evenFromQueue(queue);
	
	displayQueue(evenQueue);
	
	visualizeQueue(evenQueue);
	
	return 0;
}
