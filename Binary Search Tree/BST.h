#ifndef BST
#define BST

#define SIZE 6

typedef struct {
	int month, day, year;
} Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node{
	Product item;
	struct node *left, *right, *next;
} NodeType, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;
	

extern Product pList[];

NodePtr *findSuccessor(NodePtr *head);
Product createProduct(char name[], float price, int qty, int month, int day, int year);
bool insertNode(NodePtr *head, Product p);
NodePtr searchNode(NodePtr head, char prodName[]);
NodePtr deleteNode(NodePtr *head, char prodName[]);

void BSF(NodePtr head);
Queue createQueue();
NodePtr peekFrontQueue(Queue q);
NodePtr peekRearQueue(Queue q);
bool enQueue(Queue *q, NodePtr node);
bool deQueue(Queue *q);
bool isEmpty(Queue q);


void inOrderDFS(NodePtr head);
void postOrderDFS(NodePtr head);
void preOrderDFS(NodePtr head);


#endif
