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
	
	populateOpenTable(&myHash, "yellow", "FFFF00") ? displayValue(myHash, "yellow") : printf("\nError populating list");
	populateOpenTable(&myHash, "cyan", "00FFFF") ? displayValue(myHash, "cyan") : printf("\nError populating list");
	populateOpenTable(&myHash, "neon rose", "FF0080") ? displayValue(myHash, "cyan") : printf("\nError populating list");
	
//	populateClosedTable();
	return 0;
	
	
}
