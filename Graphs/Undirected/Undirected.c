#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

bool threshold(GraphList hash){
	return hash.threshold <= THRESHOLD;
}

int hashFunction(char key){
	return (key * HASHCODE) * HASHCODE;
}

VertexPtr *resizeTable(VertexPtr *table, int count, int size){
	
	VertexPtr *newTable = (VertexPtr *) malloc(sizeof(VertexPtr) * size);
	
	if(newTable != NULL){
		
		int i;
		for(i = 0; i < size; i++){
			newTable[i] = NULL;
		}
		
		int travIndex, rehashed;
		for(travIndex = 0, rehashed = 0; rehashed < count; travIndex++){
			
			if(table[travIndex] != NULL){
				
				VertexPtr trav = table[travIndex];
				while(trav != NULL){
					
//					int keyIndex = hashFunction(key)%newSize;
//					VertexPtr node = (VertexPtr*) malloc(sizeof(Vertex));
//					node = trav;
					if(addVertex(newTable, trav->key, size)) {
					
						VertexPtr vptr = searchVertex(newTable, trav->key, size);
						int length = strlen(trav->connections);
						vptr->connections = (char *) malloc(sizeof(length) * size);
					
						if(vptr->connections != NULL) strcpy(vptr->connections, trav->connections);
						free(trav->connections);
						trav = trav->next;
						rehashed++;
					} else {
						printf("\nError inserting to new table!!");
					}
				}
				
				
			}
		}
		free(table);
		
	}
	return newTable;
}


void populateList(GraphList *list){

	int i, x, vertexes, edges;
	char vertex = 'A';

	printf("\n\nHow many Vertexes will you add: ");
	scanf("%d", &vertexes);

	if(vertexes < 30){
		
		for(i = 0; i < vertexes; i++, vertex++){
			
			if(!threshold(*list)){
			
				list->table = resizeTable(list->table, list->count, list->size*2);
				list->size *= 2;
			}
		
			if(addVertex(list->table, vertex, list->size)){
				list->count++;
			} 
			
			list->threshold = (float)list->count/list->size;
		}
		for(i = 0, edges = 0, vertex = 'A'; i < list->count; i++, vertex++){
			
			Vertex *searchedNode = searchVertex(list->table, vertex, list->size);
			
			printf("\nHow many edges will you input for %c: ", searchedNode->key);
			scanf("%d", &edges);
			
			for(x = 0; x < edges; x++){
			
				printf("Edge 1: ");
				searchedNode->connections[x] = getch();
				
				printf("%c\n", searchedNode->connections[x]);
				addEdge(searchedNode, searchVertex(list->table, searchedNode->connections[x], list->size));
			}
			
			printf("\nEdges: %s-%d", searchedNode->connections, searchedNode->count);
		}
	} else {
		printf("\nToo much!!");
	}
}

bool addVertex(VertexPtr *table, char key, int size){
	
	bool retVal = false;
	int keyIndex = hashFunction(key)%size;
	VertexPtr node = (VertexPtr) malloc(sizeof(Vertex));
	
	if(node != NULL){
		
		node->key = key;
		node->size = size;
		node->count = 0;
		node->next = NULL;
		node->connections = (char *) malloc(sizeof(char) * size);

		if(table[keyIndex] == NULL){
			table[keyIndex] = node;
		} else {
			
			VertexPtr travV = table[keyIndex];
			while(travV->next != NULL){
				travV = travV->next;
			}
			travV->next = node;
		}
		retVal = true;
	}
	
	return retVal;
}

bool addEdge(Vertex *vertex1, Vertex *vertex2){
	
//	vertex2->connections = (Vertex*) malloc(sizeof(Vertex) * (vertex2->size + 1));
//	printf("\nVertex1&Vertex2: %c & %c", vertex1->key, vertex2->key);
	bool retVal = false;
	printf("\nVertex1 connections & count: %s - %d\n", vertex1->connections, vertex1->count);
	int i;
		
	if(vertex1->size == vertex1->count){
		
		char *newConnections = (char*) malloc(sizeof(char) * (vertex1->size*2));
		strcpy(newConnections, vertex1->connections);
		free(vertex1->connections);
		vertex1->connections = newConnections;
	}
	
	for(i = 0; i < vertex2->size && vertex2->connections[i] == vertex1->key; i++){}
	
	if(i >= vertex2->size){
		
		vertex1->connections[vertex1->count] = vertex2->key;
		addEdge(vertex2, vertex1) ? printf("\nSuccess adding edge %c", vertex1->key) : printf("\nError adding edge %c", vertex1->key);
//		printf("\nVertex count: %d\n", vertex1->count++);
		vertex1->count++;
		retVal = true;
	}
	
	return retVal;
}

Vertex *searchVertex(VertexPtr *table, char key, int size){
	
	int keyIndex = hashFunction(key)%size;
	
	Vertex *searchedVertex = NULL;
	
	if(table[keyIndex]->key == key){
		
		searchedVertex = table[keyIndex];
//		printf("\nSearched Vertex: %c", searchedVertex->key);
	} else {
		Vertex *trav = table[keyIndex]->next;
		while(trav->key == key){
			trav = trav->next;
		}
		if(trav != NULL){
			searchedVertex = trav;
		}
		
	}
	
	return searchedVertex;
}

void populateMatrix(int matrix[VERTEX][VERTEX]){
	
	int x, y, edge;
	char node = 'A', destination;
	for(x = 0; x < VERTEX; x++, node++){
		for(y = 0, destination = 'A'; y < VERTEX; y++, destination++){
			printf("\nEnter Edge of [%c][%c]: ", node, destination);
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
2
5
3
BCD4
ACDE3
ABD4
ABCE2
BD
**/


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
