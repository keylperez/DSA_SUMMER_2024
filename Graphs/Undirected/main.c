#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Undirected.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int matrix[VERTEX][VERTEX];
	
	initMatrix(matrix);
	displayMatrix(matrix);
	populateMatrix(matrix);
	displayMatrix(matrix);
	
	GraphList graph;
	
	printf("GRAPHS!!\n=======================================");
	
	int task;
	while(task != 0){
		printf("\nWhat task do you want to do(1-AddVertex): ")
		switch(task){
			case 0:
				exit();
				break;
			case 1:
				populateList(&graph);
				break;
		}
	}
	
	return 0;
}
