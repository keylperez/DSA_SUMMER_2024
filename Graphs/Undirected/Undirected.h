#ifndef UNDIRECTED
#define UNDIRECTED

#define VERTEX 5
#define SIZE 10
#define THRESHOLD 0.65
#define HASHCODE 31
#define ROW 12

typedef struct vertex{
	char key;
	int size;
	int count;
	char *connections;
	struct vertex *next;
} Vertex, VertexPtr*;

typedef struct{
	VertexPtr *table;
	float threshold;
	int size;
	int count;
} GraphList;

void initMatrix(int matrix[VERTEX][VERTEX]);
void initList(GraphList *hash);
GraphList createList();
VertexPtr *resizeTable(GraphList *hash);

bool threshold(GraphList hash);
int hashFunction(char key);

void populateList(GraphList *list);
bool addVertex(VertexPtr *table, char key, int size);
bool addEdge(VertexPtr *vertex1, VertexPtr *vertex2);

void populateMatrix(int matrix[VERTEX][VERTEX]);

void displayMatrix(int matrix[VERTEX][VERTEX]);

#endif
