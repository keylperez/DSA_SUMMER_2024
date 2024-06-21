#ifndef CPU_SCHEDULING
#define CPU_SCHEDULING

typedef struct processNode{
	
	int burstTime;
	int arrivalTime;
	int completionTime;
	int executionTime;
	int turnAroundTime;
	int waitingTime;
	struct processNode* next;
} Process, ProcessPtr;

typedef struct {
	ProcessPtr
};

FirstComeFirstServe();

#endif
