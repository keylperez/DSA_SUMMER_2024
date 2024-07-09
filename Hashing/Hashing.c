#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"


char colors[ROW][2][20] = {
	{"yellow", "FFFF00"},
	{"cyan", "00FFFF"},
	{"neon rose", "FF0080"},
	{"red", "FF0000"},
	{"orange", "FF8000"},
	{"yellow green", "80FF00"},
	{"green", "00FF00"},
	{"spring green", "800080"},
	{"skyblue", "0080FF"},
	{"blue", "0000FF"},
	{"purple", "8000FF"},
	{"magenta", "FF00FF"}
};

SetNodePtr *newTable(int size){
	
	SetNodePtr *newTable = malloc(sizeof(SetNodePtr) * size);
	
	int i;
	if(newTable != NULL){
		
		for(i = 0; i < size; i++){
			newTable[i] = NULL;
		}
	}
	return newTable;
}

HashTable createHash(int size){
	
	HashTable newHash;
	newHash.size = size;
	newHash.Set = newTable(size);
	newHash.threshold = 0;
	newHash.count = 0;	
	
//	if(newHash.Set != NULL){
//		
//		int i;
//		for(i = 0; i < newHash.size; i++){
//			newHash.Set[i] = NULL;
//		}
//	}
	return newHash;
}

SetNodePtr *resizeTable(HashTable *hash, int size){
		
		SetNodePtr *newTable = malloc(sizeof(SetNodePtr) * size);
	
		int i;
		if(newTable != NULL){
			
			for(i = 0; i < size; i++){
				newTable[i] = NULL;
			}
		}
		
		SetNodePtr travPtr;
		SetNodePtr newNode;
		int travIndex, rehashed;
		
		for(travIndex = 0, rehashed = 0; rehashed < hash->count; travIndex++){
			if(hash->Set[travIndex] != NULL) {
					
					travPtr = hash->Set[travIndex];
			
					while(travPtr != NULL) {
						
						newNode = deleteHash(hash, travPtr->key);
						if(!insertHash(newTable, travPtr->key, travPtr->value, size)) printf("\nError insert");
						travPtr = travPtr->next;
						rehashed++;
					}
			
			}
		}
		
		free(hash->Set);
		hash->size = hash->size*2;
		
		return &(*newTable);

}

void populateTable(HashTable *hash){
		
		int x;
		for(x = 0; x < ROW; x++){
			
			if(!threshCheck(*hash)) {
				visualizeTable(*hash);
				hash->Set = resizeTable(hash, hash->size*2);
			}
			
			if(insertHash(hash->Set, colors[x][0], colors[x][1], hash->size)) {
				
				hash->count++;
				hash->threshold = (float)hash->count/(float)hash->size;
				SetNodePtr retNode = searchHash(*hash, colors[x][0]);
//				printf("\nKey: %s\nValue: %s\n", retNode->key, retNode->value);  
			} 
			else {
				printf("Error inserting Hash");
			}
		}
	
//	return *hash;
}


bool insertHash(SetNodePtr *table, char key[], char value[], int size){

	bool retVal = false;
	
	int keyIndex = hashFunction(key)%size;
	SetNodePtr newNode = (SetNodePtr) malloc(sizeof(SetNode));
	if(newNode != NULL){
		
		strcpy(newNode->key, key);
		strcpy(newNode->value, value);
		newNode->occupied = true;
		newNode->next = NULL;
		newNode->prev = table[keyIndex];
		
		
		if(table[keyIndex] != NULL) {
			
			SetNodePtr trav = table[keyIndex];
			
			while(trav->next != NULL){
				trav = trav->next;
			}
			trav->next = newNode;
			newNode->prev = trav;
			
			printf("\nKey: %s\nValue: %s\nIndex: %d\n", trav->key, trav->value, keyIndex);  
			
		} 
		else {
			table[keyIndex] = newNode;
			
			printf("\nKey: %s\nValue: %s\nIndex: %d\n", table[keyIndex]->key, table[keyIndex]->value, keyIndex);  
		}
		
		
		
		retVal = true;
	} else {
		printf("\nError allocating memory");
	}
	return retVal;
}


SetNodePtr deleteHash(HashTable *hash, char key[]){
	
	int keyIndex = hashFunction(key) % hash->size;
	
		SetNodePtr trav = hash->Set[keyIndex];		
		
		if(trav != NULL){
			while(strcmp(trav->key, key) != 0 && trav != NULL){
				trav = trav->next;
			}
			
			if(trav->prev != NULL) {
				trav->prev->next = trav->next;
			} else {
				hash->Set[keyIndex] = trav->next;
			}
			if(trav->next != NULL) trav->next->prev = trav->prev;
			
			
		} else {
			printf("\nKey %s does not exist\ntrav->key: %s", key, trav->key);
		}
	
	return trav;
	
}

SetNodePtr searchHash(HashTable hash, char key[]){
	
	int keyIndex = hashFunction(key) % hash.size;
	
	SetNodePtr trav = hash.Set[keyIndex];
	
	if(trav != NULL){
		while(strcmp(trav->key, key) != 0 && trav != NULL){
			trav = trav->next;
		}
	} else {
		printf("\nValue of Key not found");
	}

	return trav;
}

bool threshCheck(HashTable hash){
	return hash.threshold < THRESHOLD;
}

int hashFunction(char key[]){
	
	int keyIndex, i;

	for(i = 0, keyIndex = 0; key[i] != '\0'; i++, keyIndex += key[i]){}
	
	return keyIndex;
}

void visualizeTable(HashTable hash){
	
	int travIndex;
	
	SetNodePtr travPtr;
	
	printf("\n\n%-7s%-10s", "Index", "Nodes...");
	
	for(travIndex = 0; travIndex < hash.size; travIndex++){
		
		travPtr = hash.Set[travIndex];
		
		if(travPtr != NULL){
			
			printf("\n\n%-3d -> ", travIndex);
			
			while(travPtr != NULL){
				
				printf("%-12s -> ", travPtr->key);
				travPtr = travPtr->next;
			}
			
			travPtr = hash.Set[travIndex];
			printf("\n%-3s <- ", " ");
			
			while(travPtr != NULL){
			
				printf("%-12s <- ", travPtr->value);
				travPtr = travPtr->next;
			}	
		}
	}
}


