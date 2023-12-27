#include "tree.h"
#include <limits.h>

/////////////<BST>/////////////////

static void BstTreeMaxRec(const Node* n, const ElemType** max)
{
	if (n == NULL)
	{
		return;
	}


	*max = TreeGetRootValue(n);


	BstTreeMaxRec(n->right, max);
}

const ElemType* BstTreeMax(const Node* n)
{
	if (n == NULL)
	{
		return NULL;
	}

	ElemType* max = TreeGetRootValue(n);
	BstTreeMaxRec(n, &max);
	return max;
}



//////////<NON BST>//////////////

static void TreeMaxRec(const Node* n, const ElemType** best, int liv, int* livbest)
{
	if (TreeIsEmpty(n))
	{
		return;
	}

	if (ElemCompare(TreeGetRootValue(n), *best) > 0 || (ElemCompare(TreeGetRootValue(n), *best) == 0 && (liv < *livbest)))
	{
		*best = TreeGetRootValue(n);
		*livbest = liv;
	}

	TreeMaxRec(n->left, best, liv + 1, livbest);
	TreeMaxRec(n->right, best, liv + 1, livbest);
}

const ElemType* TreeMax(const Node* n)
{
	if(n == NULL)
	{
		return NULL;
	}

	const ElemType* best = TreeGetRootValue(n);
	int livello = 0;
	int livelMax = 0;
	
	TreeMaxRec(n, &best, 0, &livelMax);

	return best;
}