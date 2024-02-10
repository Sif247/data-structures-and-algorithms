#include "tree.h"

Node* Invert(Node* t)
{
	if (t == NULL)
	{
		return NULL;
	}

	Node* left = Invert(t->left);
	Node* right = Invert(t->right);

	t->left = right;
	t->right = left;

	return t;
}
/*
int main(void)
{
	ElemType e[] = { 1,2,3 };

	Node* root = TreeCreateRoot(e + 1,
		TreeCreateRoot(e + 2, NULL, NULL),
		TreeCreateRoot(e, NULL, NULL));

	Node* ris = Invert(root);
	return 0;
}
*/