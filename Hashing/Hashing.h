#ifndef HASHING
#define HASHING

#define SIZE 10
#define THRESHOLD 0.65
#define HASHCODE 31
#define ROW 12

/*****************************
["red"]				= "FF0000"
["orange"]			= "FF8000"
["yellow"]			= "FFFF00"
["yellow green"]	= "80FF00"
["green"]			= "00FF00"
["spring green"]	= "800080"
["cyan"]			= "00FFFF"
["skyblue"]			= "0080FF"
["blue"]			= "0000FF"
["purple"]			= "8000FF"
["magenta"]			= "FF00FF"
["neon rose"]		= "FF0080"
*****************************/

extern char colors[ROW][2][20];

typedef struct node{
    char value[7];
    char key[20];
    bool occupied;
    struct node *next;
    struct node *prev;
} SetNode, *SetNodePtr;

//typedef SetNodePtr HashArray[SIZE];
// incorrect naming after correcting structure concept; too lazy to change hehe
typedef struct{
	SetNodePtr *Set;
    float threshold;
    int size;
    int count;
} HashTable;

SetNodePtr *newTable(int size);
HashTable createHash(int size);
void populateTable(HashTable *hash);

bool insertHash(SetNodePtr *table, char key[], char value[], int size);
SetNodePtr searchHash(HashTable hash, char key[]);
SetNodePtr deleteHash(HashTable *hash, char key[]);

bool threshCheck(HashTable hash);

int hashFunction(char key[]);

void visualizeValue(HashTable hash);

#endif
