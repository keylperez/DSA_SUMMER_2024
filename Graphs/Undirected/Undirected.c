#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
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
	hash->lastNode = 'A';
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
	list.lastNode = 'A';
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
	
	printf("\nTHRESHOLD EXCEEDED!! Reallocating table...");
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
					if(addVertex(newTable, trav->key, size) != NULL) {
					
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
	char vertex = list->lastNode;
	printf("\n\nHow many Vertexes will you add: ");
	scanf("%d", &vertexes);

	// not overload the graph
	if(vertexes < 20){
		
		// loop through number of vertex
		for(i = 0; i < vertexes; i++, vertex++){
			
			if(!threshold(*list)){
			
				list->table = resizeTable(list->table, list->count, list->size*2);
				list->size *= 2;
				printf("\nNew size of table is now %d with %d vertexces", list->size, list->count);
			}
		
//			if(addVertex(list->table, vertex, list->size)){
				Vertex *added = addVertex(list->table, vertex, list->size);
				if(added != NULL){
					
					printf("\nKey: %c - %s", added->key, added->connections);
					list->count++;
				} else {
					printf("\nCould not add vertex in population function...");
				}
//			} 
			
			list->threshold = (float)list->count/list->size;
		}
		for(i = 0, edges = 0; i < list->count; i++, list->lastNode++){
			
			Vertex *searchedNode = searchVertex(list->table, list->lastNode, list->size);
			
			if(searchedNode != NULL){
				
				printf("\nHow many edges will you input for %c: ", searchedNode->key);
				scanf("%d", &edges);
				
				for(x = 0; x < edges; x++){
				
					printf("Edge %d: ", x);
					char input = toupper(getch());
					
					printf("%c\n", input);
					addEdge(searchedNode, searchVertex(list->table, input, list->size));
				}
				
				printf("\nEdges: %s-%d", searchedNode->connections, searchedNode->count);
				
			} else {
				printf("\nSearched Node is NULL(populate function)");
			}
		}
	} else {
		printf("\nToo much!!");
	}
}

// bool addVertex(VertexPtr *table, char key, int size){
Vertex* addVertex(VertexPtr *table, char key, int size){
	
//	bool retVal = false;
	int keyIndex = hashFunction(key)%size;
	VertexPtr node = (VertexPtr) malloc(sizeof(Vertex));
	Vertex* exist = searchVertex(table, key, size);
	
	if(node != NULL && exist == NULL){
		
		node->key = key;
		node->size = size;
		node->count = 0;
		node->next = NULL;
		node->connections = (char *) malloc(sizeof(char) * size);
		if(node->connections != NULL){
			node->connections[0] = '\0';

			if(table[keyIndex] == NULL){
				table[keyIndex] = node;
				exist = table[keyIndex];
			} else {
				
				VertexPtr travV = table[keyIndex];
				while(travV->next != NULL){
					travV = travV->next;
				}
				travV->next = node;
				exist = travV->next;
			}
//			retVal = true;
		} else {
			exist = NULL;
			free(node->connections);
			free(node);
		}
	}
	
//	return retVal;
	return exist;
}

bool addEdge(Vertex *vertex1, Vertex *vertex2){
	
	bool retVal = false;
	int i;
		
	if(vertex1->count == vertex1->size - 1){
		
		char *newConnections = (char*) malloc(sizeof(char) * (vertex1->size*2));
		if(newConnections != NULL){
			
			strcpy(newConnections, vertex1->connections);
			free(vertex1->connections);
			vertex1->connections = newConnections;
			vertex1->size *= 2;
			printf("\nVertex %c edges full!! Reallocating to size %d...", vertex1->key, vertex1->size);
			printf("\n%-20s%s", "Vertex Edges: ", vertex1->connections);
		}
	} 
	
	if(vertex1->connections != NULL){
				
		for(i = 0; vertex1->connections[i] != vertex2->key && vertex1->connections[i] != '\0'; i++){}
		
		if(vertex1->connections[i] != vertex2->key){
			vertex1->connections[vertex1->count++] = vertex2->key;
			vertex1->connections[vertex1->count] = '\0';
			addEdge(vertex2, vertex1);
			retVal = true;
		} 
	}
	
	return retVal;
}

Vertex *searchVertex(VertexPtr *table, char key, int size){
	
	int keyIndex = hashFunction(key)%size;
	
	Vertex *searchedVertex = table[keyIndex];
	
	if(searchedVertex != NULL){
		
		if(searchedVertex->key == key){
			
			searchedVertex = table[keyIndex];
	//		printf("\nSearched Vertex: %c", searchedVertex->key);
		} else {
			Vertex *trav = table[keyIndex]->next;
			if(trav != NULL){
				while(trav->key != key){
					trav = trav->next;
				}
				if(trav != NULL){
					searchedVertex = trav;
				}
			} else {
				searchedVertex = NULL;
			}
			
		}
	}
	
	return searchedVertex;
}

void displayList(GraphList list){
	
	printf("\n\nTABLE DETAILS:");
	printf("\n%-20s%10.2f", "Threshold:", list.threshold);
	printf("\n%-20s%10d","Size:",  list.size);
	printf("\n%-20s%10d", "No. of Vertexes:", list.count);
	printf("\n%-20s%10c", "Next Vertex:", list.lastNode);
	printf("\n===============================");
	printf("\nVertexes and Edges:");
	
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
BD2
5
3
BDE2
AC4
ABCD2
AD3
ABD
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
