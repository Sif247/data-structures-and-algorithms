#include "tree.h" 

void InOrderTraversal(Node* root, Node** prev)
{
    if (root != NULL)
	{
        InOrderTraversal(root->left, prev);

        if (*prev != NULL)
		{
            (*prev)->next = root;
        }
        *prev = root;

        InOrderTraversal(root->right, prev);
    }
}

void PopulatingNext(Node* t)
{
    Node* prev = NULL;
    InOrderTraversal(t, &prev);
}

int main(void)
{
	ElemType e[] = { 2,1,7,4,3,5,0 };

	Node* root = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 3, NULL, NULL)),
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 5, NULL, NULL),
			TreeCreateRoot(e + 6, NULL, NULL)));

	PopulatingNext(root);
	return 0;
}
