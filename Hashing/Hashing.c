#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"

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

bool populateOpenTable(HashTable *hash, char key[], char value[]){
	
	int index = hashFunction(key);
	SetNode newNode, *trav;
//	SetNodePtr trav = &(hash->Set[index]);
	trav = &(hash->Set[index]);
	newNode.occupied = true;
	
	if(!threshCheck(*hash) ){

		memcpy(newNode.hexCode, value, sizeof(value) - 1);
		
		if(isOccupied(*hash, index)) {
			
			*trav = collisionHandle(trav);
			*trav->next = newNode;
		} else {
			*trav = newNode;
		}		
		
		hash->threshold++;
	}
	
	return true;
}

bool threshCheck(HashTable hash){
	return hash.threshold >= THRESHOLD * SIZE;
}

SetNode collisionHandle(SetNode *trav){
	
	while(!(trav->next != NULL)){
		trav = trav->next;
	}
	
	return *trav;
}

int hashFunction(char key[]){
	
	int keyIndex, i;
	for(i = 0, keyIndex = 0; key[i] != '\0'; i++, keyIndex += key[i]){}
	
	return keyIndex %= 10;
}

SetNode searchTable(HashTable hash, char key[]){

	int index = hashFunction(key);
	SetNode *trav;
	trav = &hash.Set[index];
	if(strcmp(trav->hexCode, key) != 0){
		
		*trav = collisionHandle(trav);
	}
	
	return *trav;
}

void displayValue(HashTable hash, char key[]){
	
	int index = hashFunction(key);
	
	if(strcmp(hash.Set[index].hexCode, key) == 0){
		printf("\nindex %d value: %s", index, hash.Set[index].hexCode);
	}
}


