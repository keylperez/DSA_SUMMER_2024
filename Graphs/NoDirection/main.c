#include <stdio.h>
#include <stdlib.h>
#include "noDirection.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int matrix[ROW][COLUMN];
	
	initMatrix(matrix);
	displayGraph(matrix);
	populateGraph(matrix);
	displayGraph(matrix);
	return 0;
}
