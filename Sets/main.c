#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Sets.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*****************************************************************************
Create a program to find the union and intersection (Array implementation)

 - 2 Functions that accepts 2 sets and find Union & Intersection
 - Functions to add or delete values in the set.
 - Keep the integrity of the 2 initial sets whenfinding Union & Intersection
 - Display resulting Unions & Intersections

******************************************************************************/

int main() {
	
	SetStruct A, B = createSet();
	int setA[] = {1, 6, 3, 7, 8, 2};
	int setB[] = {1, 2, 4, 5};
	
	printf("\nSize set: %d", sizeof(setA)/sizeof(int));
	
	int i;	
	
	for(i = 0; i < sizeof(setA)/sizeof(int); i++){
		if(!addElem(&A, setA[i])) printf("\nError adding element to Set A: %d", setA[i]);
	}
	
	for(i = 0; i < sizeof(setB)/sizeof(int); i++){
		if(!addElem(&B, setB[i])) printf("\nError adding element to Set B: %d", setB[i]);
	}
	
	printf("\nSET A: ");
	displaySet(A);
	printf("\nSET B: ");
	displaySet(B);
	
	printf("\nSET A: ");
	displaySet(A);
	
	SetStruct unionSet = findUnion(A, B);
	
	printf("\nSET UNION: ");
	displaySet(unionSet);
	
	SetStruct interSet = findIntersection(A, B);
	printf("\nSET INTERSECTION: ");
	displaySet(interSet);
	
	printf("\nSET A: ");
	displaySet(A);
	printf("\nSET B: ");
	displaySet(B);
	
	if(!deleteElem(&A, 3)) printf("\nError Deletion\n");	
	printf("\nSET A: ");
	displaySet(A);
	
	return 0;
}
