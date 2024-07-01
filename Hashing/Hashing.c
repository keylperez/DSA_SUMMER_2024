#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"

bool DEBUG_SWITCH = true;

HashTable createHash(int size){
	
	HashTable newHash;
	newHash.size = size;
	newHash.threshold = 0;
	newHash.count = 0;
	
	int i;
	for(i = 0; i < size; i++){
		newHash.Set[i].occupied = false;
		newHash.Set[i].next = NULL;
	}
	
	return newHash;
}

bool isOccupied(HashTable hash, int index){
	
	return hash.Set[index].occupied;
	
}

bool insertHash(HashTable *hash, char key[], char value[]){
	
	bool retVal = false;
	
	int keyIndex = hashFunction(key)%hash->size;
//	SetNode newNode, *trav;
	SetNodePtr newNode = (SetNodePtr) malloc(sizeof(SetNode));
	
	if(newNode != NULL){
		
		SetNodePtr trav = &(hash->Set[keyIndex]);
		
		if(DEBUG_SWITCH){
		
			printf("\n\nDebug Info:");
			printf("\nIndex: %d", keyIndex);
		}
		printf("\nKey: %s", strcpy(newNode->key, key));
		printf("\nValue: %s", strcpy(newNode->value, value));
		newNode->occupied = true;
		newNode->next = NULL;
	
		if(isOccupied(*hash, keyIndex)) {
			
			while(trav->next != NULL){
				trav = trav->next;
			}
			trav->next = newNode;
		} else {
			
			hash->Set[keyIndex] = *newNode;
		}		
		
		hash->count++;
		hash->threshold = (float)hash->count/(float)hash->size;
		retVal = true;
	} else {
		printf("\nError allocating memory");
	}
	
	if(DEBUG_SWITCH) {

		printf("\nSUCCESS FUNCTION\n");
		printf("---------------------------");
	}
	return retVal;
}

bool threshCheck(HashTable hash){
	return hash.threshold >= THRESHOLD;
}

int hashFunction(char key[]){
	
	int keyIndex, i;
	for(i = 0, keyIndex = 0; key[i] != '\0'; i++, keyIndex += key[i]){}
	
	return keyIndex;
}

void searchHash(HashTable hash, char key[]){
	
	
	printf("\n\nDISPLAY:");
	int keyIndex = hashFunction(key) % hash.size;
	
	SetNodePtr trav = &(hash.Set[keyIndex]);
	
	while(strcmp((*trav).key, key) != 0 && trav != NULL){
		trav = trav->next;
	}
	
	printf("\nHash Index: %d \nHash Value: %s", keyIndex, (*trav).value);
//	return trav->value;
}

void visualizeTable(HashTable hash){
	
	int travIndex;
	
	SetNodePtr travPtr;
	
	printf("\n\n%7s", "Index");
	
	for(travIndex = 0; travIndex < hash.size; travIndex++){
		
		while(isOccupied(hash, travIndex) && hash.Set[travIndex].next != NULL){
			
			travPtr = &(hash.Set[travIndex]);
			
			if(DEBUG_SWITCH) printf("\n\ntravPtr key: %s\n\n", (*travPtr).key);
			
			printf("\n%7d", travIndex);
			
			while(travPtr != NULL){
				
				printf("%10s -> ", (*travPtr).key);
				travPtr = travPtr->next;
			}
			
			travPtr = &(hash.Set[travIndex]);
			printf("\n%7s%10s -> ", " ", (*travPtr).value);
			
			while(travPtr != NULL){
			
				printf("%10s -> ", (*travPtr).value);
				travPtr = travPtr->next;
			}
		}
	}
}


