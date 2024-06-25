#ifndef CPU_SCHEDULING
#define CPU_SCHEDULING

typedef struct{
	char processName;
	int burstTime;
	int arrivalTime;
	int completionTime;
	int turnAroundTime;
	int waitingTime;
} ProcessNode;

typedef struct node{
	ProcessNode elem;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr front;
	NodePtr rear;
} CPU;

void initalizeQueue(CPU *queue);
CPU createQueue();

bool isEmpty(CPU queue);

NodePtr processFront(CPU queue);
NodePtr processRear(CPU queue);

ProcessNode fillProcess(char name, int bt, int at);

bool enqueueProcess(CPU *queue, ProcessNode p);
bool dequeueProcess(CPU *queue);

//void computeProcesses(CPU *queue);
//int computeCT(CPU *queue);
int computeTAT(ProcessNode node);
int computeWT(ProcessNode node);

void displayProcesses(CPU queue);
void visualizeProcesses(CPU queue);

#endif
