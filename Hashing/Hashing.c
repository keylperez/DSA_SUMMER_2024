#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"


char colors[8][2][20] = {
	{"yellow", "FFFF00"},
	{"cyan", "00FFFF"},
	{"neon rose", "FF0080"},
	{"red", "FF0000"},
	{"orange", "FF8000"},
	{"yellow green", "80FF00"},
	{"green", "00FF00"},
	{"spring green", "800080"}
};

HashTable createHash(int size){
	
	HashTable newHash;
	newHash.size = size;
	newHash.threshold = 0;
	newHash.count = 0;
	
	int i;
	for(i = 0; i < size; i++){
		newHash.Set[i] = NULL;
	}
	
	return newHash;
}

bool populateTable(HashTable *hash){
	
	int x;
	
	for(x = 0; x < 8; x++){
		
		insertHash(hash, colors[x][0], colors[x][1]) ? searchHash(*hash, colors[x][0]): printf("Error inserting Hash");
	}
	
	return true;
}


bool insertHash(HashTable *hash, char key[], char value[]){

	bool retVal = false;
	
	int keyIndex = hashFunction(key)%hash->size;
	SetNodePtr newNode = (SetNodePtr) malloc(sizeof(SetNode));
	
	if(newNode != NULL){
		
		SetNodePtr trav = hash->Set[keyIndex];
		
		strcpy(newNode->key, key);
		strcpy(newNode->value, value);
		newNode->next = NULL;
	
		if(trav != NULL) {
			
			while(trav->next != NULL){
				trav = trav->next;
			}
			trav->next = newNode;
			trav = trav->next;
			
			
		} else {
			
			hash->Set[keyIndex] = newNode;
		}
		
		hash->count++;
		hash->threshold = (float)hash->count/(float)hash->size;
		retVal = true;
	} else {
		printf("\nError allocating memory");
	}
	return retVal;
}

bool threshCheck(HashTable hash){
	return hash.threshold < THRESHOLD;
}

int hashFunction(char key[]){
	
	int keyIndex, i;
	for(i = 0, keyIndex = 0; key[i] != '\0'; i++, keyIndex += key[i]){}
	
	return keyIndex;
}

void searchHash(HashTable hash, char key[]){
	
	
	printf("\n\nDISPLAY:");
	int keyIndex = hashFunction(key) % hash.size;
	
	SetNodePtr trav = hash.Set[keyIndex];
	
	if(trav != NULL){
		while(strcmp(trav->key, key) != 0 && trav != NULL){
			trav = trav->next;
		}
	}
	if(trav != NULL) printf("\nHash Index: %d \nHash Value: %s", keyIndex, trav->value);
//	return trav;
}

void visualizeTable(HashTable hash){
	
	int travIndex;
	
	SetNodePtr travPtr;
	
	printf("\n\n%-9s%-10s", "Index", "Nodes...");
	
	for(travIndex = 0; travIndex < hash.size; travIndex++){
		
		travPtr = hash.Set[travIndex];
		
		if(travPtr != NULL){
			
			printf("\n\n%-5d -> ", travIndex);
			
			while(travPtr != NULL){
				
				printf("%-10s -> ", travPtr->key);
				travPtr = travPtr->next;
			}
			
			travPtr = hash.Set[travIndex];
			printf("\n%-5s -> ", " ");
			
			while(travPtr != NULL){
			
				printf("%-10s -> ", travPtr->value);
				travPtr = travPtr->next;
			}	
		}
	}
}


