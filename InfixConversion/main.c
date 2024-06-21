#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Postfix.h"
#include "Prefix.h"
#include "Stack.h"

int main() {
	
	char infix[] = "3 + 2 * 5 - 4 * 8 / 2 + 2";
	int trav;
		
	char *postfix;
	postfix = Postfix(infix);
	
	printf("\n\n%s", &postfix);
		
	return 0;
}
