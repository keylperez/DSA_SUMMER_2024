#ifndef SETS
#define SETS

#define SIZE 20

typedef int SET[SIZE];

typedef struct {
	SET set;
	int countElem;
}SetStruct;

SetStruct createSet();

bool isEmpty(SetStruct X);
bool isFull(SetStruct X);

SetStruct findUnion(SetStruct X, SetStruct Y);
SetStruct findIntersection(SetStruct X, SetStruct Y);

bool addElem(SetStruct *X, int elem);
bool deleteElem(SetStruct *X, int elem);


void displaySet(SetStruct X);

#endif
