#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int items, qty, day, month, year, input, display;
	float price;
	char name[20];
	
	Product p;
	
	printf("How many products will you insert? (input 0 for automatic dataset): ");
	scanf("%d", &items);
	
	NodePtr head;
	init(&head);
	
	if(items == 0){
		
		int i;
		for(i = 0; i < SIZE; i++){
			if(!insertNode(&head, pList[i])) printf("\nError inserting node %s", pList[i].prodName);
		}
			
	} else {
		
		int i;
		for(i = 0; i< items; i++){
			
			printf("\n%-25s: ", "Product Name");
			scanf("%s", &name);
			printf("%-25s: ", "Product Price");
			scanf("%f", &price);
			printf("%-25s: ", "Product Quantity");
			scanf("%d", &qty);
			printf("%-25s: ", "Expiry Date(mm/dd/yyyy)");
			scanf("%d-%d-%d", &month, &day, &year);
			p = createProduct(name, price, qty, month, day, year);
	//		printf("%s - %.2f - %d - %d-%d-%d", p.prodName, p.prodPrice, p.prodQty, p.expDate.month, p.expDate.day, p.expDate.year);
			if(!insertNode(&head, p)) printf("\nError inserting node %s\n", name);
		}
	}
	
	NodePtr node;
	
	do{
		
		printf("\n\nInput action(1-Insert/2-Search/3-Delete/4-Display/0-Exit): ");
		scanf("%d", &input);
		switch(input){
			case 1:
				
				printf("\n%-25s: ", "Product Name");
				scanf("%s", &name);
				printf("%-25s: ", "Product Price");
				scanf("%f", &price);
				printf("%-25s: ", "Product Quantity");
				scanf("%d", &qty);
				printf("%-25s: ", "Expiry Date(mm/dd/yyyy)");
				scanf("%d-%d-%d", &month, &day, &year);
				p = createProduct(name, price, qty, month, day, year);
		//		printf("%s - %.2f - %d - %d-%d-%d", p.prodName, p.prodPrice, p.prodQty, p.expDate.month, p.expDate.day, p.expDate.year);
				if(!insertNode(&head, p)) printf("\nError inserting node %s\n", name);
				break;
			case 2:
				
				printf("\nNode to search: ");
				scanf("%s", &name);
	
				node = searchNode(head, name);
				
				printf("\nSearched node: %s", node->item.prodName);
				break;
			case 3:
				printf("\nNode to delete: ");
				scanf("%s", &name);
				
				NodePtr *nodeptr = deleteNode(&head, name);
				if(*nodeptr != NULL){
					
					printf("\nDeleted node: %s", name);
				} else {
					printf("\nNode not found!!");
				}
				break;
			case 4:
				
				printf("\nInput order of display(1-Inorder/2-PostOrder/3-PreORder): ");
				scanf("%d", &display);
				switch(display){
					case 1:
						printf("\nIn Order:");
						inOrderDFS(head);
						break;
					case 2:
						printf("\nPost Order: ");
						postOrderDFS(head);
						break;
					case 3:
						printf("\nPre Order: ");
						preOrderDFS(head);
						break;
				}
				break;
		}
	} while(input != 0);
	
	
	
	
	return 0;
}
