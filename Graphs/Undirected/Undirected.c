#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Undirected.h"

void initMatrix(int matrix[VERTEX][VERTEX]){
	int x, y;
	for(x = 0; x < VERTEX; x++){
		for(y = 0; y < VERTEX; y++){
			matrix[x][y] = 0;
		}
	}
}

void initList(GraphList *hash){

	hash->threshold = 0;
	hash->size = SIZE;
	hash->count = 0;
	hash->table = (VertexPtr *)malloc(sizeof(VertexPtr) * hash->size);
	int i;
	for(i = 0; i < hash->size; i++){
		hash->table[i] = NULL;
	}
}

GraphList createList(){
	GraphList list;
	list.threshold = 0;
	list.size = SIZE;
	list.count = 0;
	list.table = (VertexPtr *) malloc(sizeof(VertexPtr) * list.size);
	int i;
	for(i = 0; i < list.size; i++){
		list.table[i] = NULL;
	}
	return list;
}

VertexPtr *resizeTable(VertexPtr *table, int count){
	
	int newSize = hash->size * 2;
	VertexPtr *newTable = malloc(sizeof(VertexPtr) * newSize);
	
	if(newTable != NULL){
		
		int i;
		for(i = 0; i < newSize; i++){
			newTable[i] = NULL;
		}
		
		int travIndex, rehashed;
		for(travIndex = 0, rehashed = 0; rehashed < hash->count; travIndex++){
			
			if(table[travIndex] != NULL){
				
				VertexPtr trav = hash->table[travIndex];
				while(trav != NULL){
					
//					int keyIndex = hashFunction(key)%newSize;
//					VertexPtr node = (VertexPtr*) malloc(sizeof(Vertex));
//					node = trav;
					if(addVertex(newTable, trav->key, trav->connections)) {
//						deleteVertex(hash, trav->key);
						trav = trav->next;
						rehashed++;
					} else {
						printf("\nError inserting to new table!!");
					}
				}
				
				
			}
		}
		
	}
	return &(*newTable);
}

bool threshold(GraphList hash){
	return hash->threshold <= THRESHOLD;
}

int hashFunction(char key){
	return (key * HASHCODE) * HASHCODE;
}

void populateList(GraphList *list){

	int i, vertexes;
	char vertex = 'A';
	printf("\n\nHow many Vertexes will you add? ");
	scanf("%d", &vertexes);
	if(vertexes <= 30){
		
			
		for(i = 0; i < vertexes; i++, vertex++){
			
			if(threshold(*list)){
				list->table = resizeTable(hash->table, hash->count);
				list->size *= 2;
			}
			if(addVertex(list->table, vertex, list->size){
				list->count++;
			} 
			list->threshold = (float)list->count/list->size;
		}	
	} else {
		printf("")
	}
}

bool addVertex(VertexPtr *table, char key, int size){
	
	int keyIndex = hashFunction(key)%size;
	VertexPtr node = (VertexPtr*) malloc(sizeof(Vertex));
	
	if(node != NULL){
		node->key = key;
		node->size = hash->size;
		node->count = 0;
		node->next = NULL;
		node->connections = (Vertex*) malloc(sizeof(Vertex) * hash->size);

		if(table[keyIndex] == NULL){
			table[keyIndex] = node;
		} else {
			
			VertexPtr *travV = table[keyIndex];
			while((*travV)->next != NULL){
				*travV = (*travV)->next;
			}
			(*travV)->next = node;
		}
	}
}

bool addEdge(VertexPtr *vertex1, VertexPtr *vertex2){
	
//	vertex2->connections = (Vertex*) malloc(sizeof(Vertex) * (vertex2->size + 1));
	
	if(vertex1->size == vertex1->count){
		
		char *newConnections = (char*) malloc(sizeof(char) * (vertex1->size*2));
		strcpy(newConnections, vertex1->connections);
		free(vertex1->connections);
		vertex1->connections = newConnections;
	}
	vertex1->connections[vertex1->count] = vertex2->key;
	
	return addEdge(vertex2, vertex1);	
}

void populateMatrix(int matrix[VERTEX][VERTEX]){
	
	int x, y, edge;
	char node = 'A', destination;
	for(x = 0; x < VERTEX; x++, node++){
		for(y = 0, destination = 'A'; y < VERTEX; y++, destination++){
			printf("Enter Edge of [%c][%c]: ", node, destination);
			scanf("%d", &matrix[x][y]);
		}
	}
}

void displayMatrix(int matrix[VERTEX][VERTEX]){
	
	int x, y, edge = 0;
	char destination;
	printf("\n\n%-5c| %-5c| %-5c| %-5c| %-5c| %-5c\n", ' ', 'A', 'B', 'C', 'D', 'E');
	
	for(x = 0, destination = 'A'; x < VERTEX; x++, destination++){
		
		printf("%-5c| ", destination);
		for(y = 0; y < VERTEX; y++){
			if(matrix[x][y] == -1){
				if(y != VERTEX -1) {
					printf("%-5c| ", ' ');
				} else {
					printf("%-5c", ' ');
				}
			}
			else if(y != (VERTEX - 1)) {
				printf("%-5d| ", matrix[x][y]);
			} else {
				printf("%-5d\n", matrix[x][y]);
			}
			if(matrix[x][y] == 1){
				edge++;
			}
		}
	}
	printf("\nEdges: %d", edge/2);
	printf("\nNodes: %d", VERTEX);
	
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
