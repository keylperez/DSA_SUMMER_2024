#ifndef HASHING
#define HASHING

#define SIZE 10
#define THRESHOLD 0.65
#define HASHCODE 31

/*****************************
["red"]				= "FF0000"
["orange"]			= "FF8000"
["yellow"]			= "FFFF00"
["yellow green"]	= "80FF00"
["green"]			= "00FF00"
["sping green"]		= "800080"
["cyan"]			= "00FFFF"
["skyblue"]			= "0080FF"
["blue"]			= "0000FF"
["purple"]			= "8000FF"
["magenta"]			= "FF00FF"
["neon rose"]		= "FF0080"
*****************************/

extern bool DEBUG_SWITCH;

typedef struct node{
    char value[7];
    char key[20];
    bool occupied;
    struct node *next;
} SetNode, *SetNodePtr;

typedef SetNode HashArray[SIZE];

typedef struct{
    HashArray Set;
    float threshold;
    int size;
    int count;
} HashTable;

HashTable createHash(int size);

bool isOccupied(HashTable hash, int index);
bool insertHash(HashTable *hash, char key[], char value[]);
void searchHash(HashTable hash, char key[]);
SetNode deleteHash(HashTable hash, char key[]);

bool threshCheck(HashTable hash);

int hashFunction(char string[]);

void visualizeValue(HashTable hash);

#endif
