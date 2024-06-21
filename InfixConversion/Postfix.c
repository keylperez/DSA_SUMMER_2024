#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Postfix.h"
#include "Stack.h"

char *Postfix(char string[]){
	
	char postfix[strlen(string)+1];
	
	printf("\n\nsizeof postfix: %d", sizeof(postfix));
	
	strcpy(postfix, string);
	
	return postfix[strlen(string)+1];
	
}
