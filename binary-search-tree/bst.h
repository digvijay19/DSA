typedef int Comapartor(void* first,void* second);

typedef struct{
	void* root;
	Comapartor *comp;
} BST;

BST createBST(Comapartor *comp);

int insert(BST* tree,void* data);

int search(BST* tree,void* data);