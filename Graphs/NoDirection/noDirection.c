#include <stdio.h>
#include <stdlib.h>
#include "noDirection.h"

void initMatrix(int matrix[ROW][COLUMN]){
	int x, y;
	for(x = 0; x < ROW; x++){
		for(y = 0; y < COLUMN; y++){
			matrix[x][y] = 0;
		}
	}
}

void populateGraph(int matrix[ROW][COLUMN]){
	
	int x, y, edge;
	char node = 'A', destination;
	for(x = 0; x < ROW; x++, node++){
		for(y = 0, destination = 'A'; y < COLUMN; y++, destination++){
			printf("Enter Edge of [%c][%c]: ", node, destination);
			scanf("%d", &matrix[x][y]);
		}
	}
}

void displayGraph(int matrix[ROW][COLUMN]){
	
	int x, y, edge;
	char destination;
	printf("\n\n%-5c| %-5c| %-5c| %-5c| %-5c| %-5c\n", ' ', 'A', 'B', 'C', 'D', 'E');
	
	for(x = 0, destination = 'A'; x < ROW; x++, destination++){
		
		printf("%-5c| ", destination);
		for(y = 0; y < COLUMN; y++){
			if(matrix[x][y] == -1){
				printf("%-5c| ", ' ');
			}
			else if(y != (COLUMN - 1)) {
				printf("%-5d| ", matrix[x][y]);
			} else {
				printf("%-5d\n", matrix[x][y]);
			}
		}
	}
}


/**
-1
1
1
1
0
1
-1
1
1
1
1
1
-1
1
0
1
1 
1
-1
1
0
1
0
1
-1
**/
