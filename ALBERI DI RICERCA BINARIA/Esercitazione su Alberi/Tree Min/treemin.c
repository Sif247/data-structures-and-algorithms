#include "tree.h"

////////////////<BST>///////////////
static void BstTreeMinRec(const Node* n, ElemType** min)
{
	if (n == NULL)
	{
		return;
	}

	*min = TreeGetRootValue(n);

	BstTreeMinRec(TreeLeft(n), min);
}

const ElemType* BstTreeMin(const Node* n)
{
	if (n == NULL)
	{
		return NULL;
	}

	ElemType *Min = TreeGetRootValue(n);
	BstTreeMinRec(n, &Min);
	return Min;
}

////////////////<NON BST>///////////////

static void  TreeMinRec(const Node* n, ElemType** min, int liv, int* livfar)
{
	if (n == NULL)
	{
		return NULL;
	}

	if (ElemCompare(TreeGetRootValue(n), *min) < 0 || (ElemCompare(TreeGetRootValue(n), *min) == 0) && (liv > *livfar))
	{
		*min = TreeGetRootValue(n);
		*livfar = liv;
	}

	TreeMinRec(TreeRight(n), min, liv + 1, livfar);
	TreeMinRec(TreeLeft(n), min, liv + 1, livfar);
}

const ElemType* TreeMin(const Node* n)
{
	if (n == NULL)
	{
		return NULL;
	}

	ElemType* Min = TreeGetRootValue(n);
	int livfar = 0;
	TreeMinRec(n, &Min, 0, &livfar);

	return Min;
}