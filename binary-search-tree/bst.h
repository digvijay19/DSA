typedef int Comapartor(void* first,void* second);

typedef struct{
	void* root;
	Comapartor *comp;
} BST;

typedef struct{
	void* left;
	void* right;
} Children;

BST createBST(Comapartor *comp);

int insertInBST(BST* tree,void* data);

int searchInBST(BST* tree,void* data);

int removeFromBST(BST* tree,void* data);

Children getChildren(BST* tree,void* parentData);