#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CPUScheduling.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int processNo, i, bt, at;
	char proc = 'A';
	CPU processQueue = createQueue();
//	CPU processQueue;
//	initializeQueue(&processQueue);
	
	printf("" 	
	"\n====================================="
	"\n||	CPU SCHEDULING CALUCATOR   ||"
	"\n||	First Come First Serve     ||"
	"\n=====================================\n");
	
	printf("\nNo. of Processes: ");
	scanf("%d", &processNo);
	
	if(isEmpty(processQueue)) printf("\nEmpty Queue");
	
	for(i = 0; i < processNo; i++){
		printf("\nProcess %c", proc);
		printf("\nBurst Time:");
		scanf("%d", &bt);
		printf("Arrival Time:");
		scanf("%d", &at);
		ProcessNode newNode = fillProcess(proc++, bt, at);

		if(!enqueueProcess(&processQueue, newNode)) printf("\nError Queueing");
	}
	
	visualizeProcesses(processQueue);
	displayProcesses(processQueue);
	
	return 0;
}
