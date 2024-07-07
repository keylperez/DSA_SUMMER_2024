#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"


int main() {
	
	HashTable myHash = createHash(SIZE);
	
	
	insertHash(myHash.Set, "yellow", "FFFF00", myHash.size) ? searchHash(myHash, "yellow") : printf("\nError populating list");
//	insertHash(&myHash, "cyan", "00FFFF") ? searchHash(myHash, "cyan") : printf("\nError populating list");
//	insertHash(&myHash, "neon rose", "FF0080") ? searchHash(myHash, "neon rose") : printf("\nError populating list");
//	insertHash(&myHash, "red", "FF0000") ? searchHash(myHash, "red") : printf("\nError populating list");
//	printf("%d", myHash.size);
	populateTable(&myHash);
	
	visualizeTable(myHash);
	
	SetNodePtr deletedHash = deleteHash(&myHash, "skyblue");
	
	printf("\nDELETED NODE\nKey: %s\nValue: %s\n", deletedHash->key, deletedHash->value);
	
	free(deletedHash);
	
	visualizeTable(myHash);
	
	
	return 0;
	
	
}
