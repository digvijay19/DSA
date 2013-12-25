typedef struct{
	void* element;
	void* next;
} Node;

typedef struct{
	void* head;
	int length;
} sList;

Node* createNode(void* element);
sList* createList();
int insert(sList* list,void* element,int position);
int remove(sList* list,int position);