#include "tree.h"
#include <stdlib.h>

Node* RemoveLeavesRec(Node* t)
{
	if (TreeIsEmpty(t) || TreeIsLeaf(t))
	{
		return NULL;
	}

	if (TreeIsLeaf(t->left) && t->left != NULL)
	{
		ElemDelete(&t->left->value);

		t->left = NULL;

		free(t->left);
		TreeDelete(t->left);
	}
	if (TreeIsLeaf(t->right) && t->right != NULL)
	{
		ElemDelete(&t->right->value);

		t->right = NULL;

		//free(t->right);
		//TreeDelete(t->right);
	}

	RemoveLeavesRec(t->left); 
	RemoveLeavesRec(t->right); 
}

Node* RemoveLeaves(Node* t)
{
	if (TreeIsEmpty(t) || TreeIsLeaf(t))
	{
		return NULL;
	}

	RemoveLeavesRec(t);
	return t;
}


/*
int main()
{
	ElemType e[] = { 3, 2, 5, 1 };

	Node* t = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL), NULL),
		TreeCreateRoot(e + 3, NULL, NULL));

	Node* ris = RemoveLeaves(t);

	TreeDelete(t);
	TreeDelete(ris);
	return 0;
}
*/