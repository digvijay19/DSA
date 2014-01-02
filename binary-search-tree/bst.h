typedef int Comapartor(void* first,void* second);

typedef struct{
	void* root;
	Comapartor *comp;
} BST;

BST createBST(Comapartor *comp);

int insertInBST(BST* tree,void* data);

int searchInBST(BST* tree,void* data);