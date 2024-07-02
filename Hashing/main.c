#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"


int main() {
	
	int size = 0;
	size += SIZE;
	HashTable myHash = createHash(size);
	
	
//	insertHash(&myHash, "yellow", "FFFF00") ? searchHash(myHash, "yellow") : printf("\nError populating list");
//	insertHash(&myHash, "cyan", "00FFFF") ? searchHash(myHash, "cyan") : printf("\nError populating list");
//	insertHash(&myHash, "neon rose", "FF0080") ? searchHash(myHash, "neon rose") : printf("\nError populating list");
//	insertHash(&myHash, "red", "FF0000") ? searchHash(myHash, "red") : printf("\nError populating list");
	
	populateTable(&myHash);
	
	
	visualizeTable(myHash);
	
	SetNode deletedHash = deleteHash(&myHash, "red");
	
	printf("\nDELETED NODE\nKey: %s\nValue: %s\n", deletedHash.key, deletedHash.value);
	
	visualizeTable(myHash);
	
	
	return 0;
	
	
}
