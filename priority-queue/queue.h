typedef char String[256];

typedef struct{
	void* element;
	void* next;
	int priority;
} Node;

typedef struct{
	Node* head;
	int length;
} PQueue;

PQueue* createQueue();
Node* createNode(void* element,int priority);
int enqueue(PQueue* queue,void* element,int priority);
void* dequeue(PQueue* queue);