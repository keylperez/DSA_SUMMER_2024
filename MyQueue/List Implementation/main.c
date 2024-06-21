#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "QueueList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	Queue queue;
	initQueue(&queue);
	
	isEmpty(queue) ? printf("\nQueue is Empty\n") : printf("\nQueue has space\n");
	dequeue(&queue);
	
	enqueue(&queue, 1) ? printf("\nEnqueue Success") : printf("\nError Queue");
	enqueue(&queue, 2) ? printf("\nEnqueue Success") : printf("\nError Queue");
	enqueue(&queue, 3) ? printf("\nEnqueue Success") : printf("\nError Queue");
	enqueue(&queue, 4) ? printf("\nEnqueue Success") : printf("\nError Queue");
	enqueue(&queue, 5) ? printf("\nEnqueue Success") : printf("\nError Queue");
	
	printf("\nFront: %d\nRear: %d\n", peek_front(queue), peek_rear(queue));
	
	isEmpty(queue) ? printf("\nQueue is Empty\n") : printf("\nQueue has space\n");
	
	enqueue(&queue, 6) ? printf("\nEnqueue Success") : printf("\nError Queue");
	
	printf("\nFront: %d\nRear: %d\n", peek_front(queue), peek_rear(queue));
	
	display(queue);
	
	dequeue(&queue);
	
	printf("\nFront: %d\nRear: %d\n", peek_front(queue), peek_rear(queue));
	
	display(queue);
	
	Queue evenQueue;
	evenQueue = evenFromQueue(queue);
	
	display(evenQueue);
	
	return 0;
}
