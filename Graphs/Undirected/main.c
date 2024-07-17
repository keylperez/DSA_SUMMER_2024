#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Undirected.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	
	int matrix[VERTEX][VERTEX];
	char vertex;

	GraphList graph = createList();
	
	printf("GRAPHS!!\n=======================================");
	
	int task = -1;
	while(task != 0){
		printf("\nWhat task do you want to do(1-Matrix Implementation/2-Add Vertex/3-Search Vertex): ");
		scanf("%d", &task);
		switch(task){
			case 0:
				int i;
				for(i = 0; i < graph.size; i++){
					if(graph.table[i] != NULL){
						
					}
				}
				break;
			case 1:
				initMatrix(matrix);
				displayMatrix(matrix);
				populateMatrix(matrix);
				displayMatrix(matrix);
				break;
			case 2:
				populateList(&graph);
				break;
			case 3:
				printf("\nWhich vertex are you looking for? ");
				scanf(" %c", &vertex);
				Vertex *vsearch = searchVertex(graph.table, vertex, graph.size);
				printf("\nKey: %c\nNumber of Edges: %d\nIndex in Hash: %d", vsearch->key, (vsearch->count, hashFunction(vsearch->key)%graph.size));
				break;
			default:
				printf("\nERROR INPUT");
				break;
		}
	}
	
	return 0;
}
