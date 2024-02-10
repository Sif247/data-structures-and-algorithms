#include "tree.h"
#include <stdlib.h>

void TreeIsMirrorRight(Node* t, ElemType* destro, int* val2)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	TreeIsMirrorRight(TreeRight(t), destro, val2);
	TreeIsMirrorRight(TreeLeft(t), destro, val2);

	destro[*val2] = t->value;
	(*val2)++;
}

void TreeIsMirrorLeft(Node* t, ElemType* mancio, int* val1)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	TreeIsMirrorLeft(TreeLeft(t), mancio, val1);
	TreeIsMirrorLeft(TreeRight(t), mancio, val1);

	mancio[*val1] = t->value;
	(*val1)++;
}

bool TreeIsMirror(Node* t)
{
	if (TreeIsEmpty(t))
	{
		return true;
	}

	ElemType mancio[200];
	int val1 = 0;
	ElemType destro[200];
	int val2 = 0;

	TreeIsMirrorLeft(t->left, mancio, &val1);
	TreeIsMirrorRight(t->right, destro, &val2);

	if (val1 != val2)
	{
		return false;
	}

	for (int j = 0; j < val1; j++)
	{
		if (destro[j] != mancio[j])
		{
			return false;
		}
	}
	return true;
}

/*
int main()
{
	Node* t = TreeCreateEmpty();

	ElemType e[] = { 0,1,4,2,1,2,4 };

	t = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 2, NULL, NULL),
				TreeCreateRoot(e + 3, NULL, NULL)),
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 5, NULL, NULL),
				TreeCreateRoot(e + 6, NULL, NULL)));

	bool ris = TreeIsMirror(t);
	return 0;
}
*/