#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Sets.h"

SetStruct createSet(){
	
	SetStruct set;
	set.countElem = 0;
	
	return set;
}

bool isEmpty(SetStruct X){
	return X.countElem == 0;
}

bool isFull(SetStruct X){
	return X.countElem == SIZE;
}

SetStruct findUnion(SetStruct X, SetStruct Y){
	
	SetStruct unionSet = createSet();
	
	int travX, travY;

	for(travX = 0; travX < X.countElem; travX++){
		
		if(!addElem(&unionSet, X.set[travX])) printf("\nError adding to union set");
		
		for(travY = 0; travY < Y.countElem && Y.set[0] != X.set[travX]; travY++){}
			if(Y.set[0] == X.set[travX]){
				if(!deleteElem(&Y, Y.set[0])) printf("\nError deleting element");
			} 
		
	}
	
	for(travY = 0; travY < Y.countElem; travY++){
		if(!addElem(&unionSet, Y.set[travY])) printf("\nError adding to union set");
	}
	
	return unionSet;
}

SetStruct findIntersection(SetStruct X, SetStruct Y)
{
	
	SetStruct intersectionSet = createSet();
	
	int x, y;
	
	for(x = 0; x < X.countElem; x++){
		for(y = 0; y < Y.countElem; y++){
			if(X.set[x] == Y.set[y]){
				if(!addElem(&intersectionSet, X.set[x])) printf("\nError adding to intersection set");
				break;
			}
		}
	}
	
	return intersectionSet;
}

bool addElem(SetStruct *X, int elem){
	
	bool addElemMsg = false;
	
	if(!isFull(*X)){
		
		X->set[X->countElem] = elem;
		X->countElem++;
		addElemMsg = true;
	}
	
	return addElemMsg;
}
bool deleteElem(SetStruct *X, int elem){
	
	bool deleteElemMsg = false;
	
	if(!isEmpty(*X)){
		
		int trav;
		
		for(trav = 0; trav < X->countElem && X->set[trav] != elem; trav++){}
		
		if(elem == X->set[trav]) {
			
			memmove(&X->set[trav], &X->set[trav+1], SIZE - trav - 1);
			X->countElem--;
			deleteElemMsg = true;
			printf("\nDeleted %d element", elem);
			
		} else {
			printf("\nElement not found in set!!");
		}
	} else {
		printf("\nSet is empty!!");
	}
	
	return deleteElemMsg;
}

void displaySet(SetStruct X){
	
	int trav;
	
	if(!isEmpty(X)){
		
		printf("{");
		for(trav = 0; trav != X.countElem; trav++){
			
			printf("%d", X.set[trav]);
			if(trav < (X.countElem - 1)){
				printf(", ");
			}
		}
		printf("}\n");
		
	} else {
		printf("\nSet is empty!!");
	}
}
