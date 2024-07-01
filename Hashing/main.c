#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Hashing.h"


int main() {
	
	int size = 0;
	size += SIZE;
	printf("%d", size);
	HashTable myHash = createHash(size);
	
	printf("\nDebug(1/0)? ");
	scanf("%d", &DEBUG_SWITCH);
	
	insertHash(&myHash, "yellow", "FFFF00") ? searchHash(myHash, "yellow") : printf("\nError populating list");
	insertHash(&myHash, "cyan", "00FFFF") ? searchHash(myHash, "cyan") : printf("\nError populating list");
	insertHash(&myHash, "neon rose", "FF0080") ? searchHash(myHash, "neon rose") : printf("\nError populating list");
	insertHash(&myHash, "red", "FF0000") ? searchHash(myHash, "red") : printf("\nError populating list");
	
	visualizeTable(myHash);
	return 0;
	
	
}
