#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Undirected.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
	
	int matrix[VERTEX][VERTEX];
	char vertex;

	GraphList graph = createList();
	
	printf("GRAPHS!!\n=======================================");
	
	int task = -1, i;
	while(task != 0){
		printf("\n\nWhat task do you want to do(1-Matrix Implementation/2-Add Vertex/3-Search Vertex/0-exit): ");
		scanf("%d", &task);
			
		switch(task){
			case 0:
				
				for(i = 0; i < graph.size; i++){
					
					if(graph.table[i] != NULL){
						
						while(graph.table[i]->next != NULL){
							
							Vertex *trav = graph.table[i];
							free(trav->connections);
							graph.table[i] = graph.table[i]->next;
							free(trav);
						}
					}
				}
				free(graph.table);
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
				vertex = toupper(getch());
				printf("%c", vertex);
				Vertex *vsearch = searchVertex(graph.table, vertex, graph.size);
				if(vsearch != NULL){
					
					printf("\nKey: %c\nEdges: %s\nNumber of Edges: %d\nIndex in Hash: %d", vsearch->key, vsearch->connections, vsearch->count, hashFunction(vsearch->key)%graph.size);
				} else {
					printf("\nSearched node does not exist");
				}
				break;
			default:
			
				printf("\nERROR INPUT");
				break;
		}
	}
	
	return 0;
}
