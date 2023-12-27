#include "tree.h"

static void CountDominantRec(const Node* n, int* count)
{
	if (TreeIsEmpty(n) || TreeIsEmpty(TreeLeft(n)) || TreeIsEmpty(TreeRight(n)))
	{
		return;
	}


	if ((n->left->value + n->right->value) < n->value)
	{
		(*count)++;
	}

	CountDominantRec(TreeLeft(n), count);
	CountDominantRec(TreeRight(n), count);
}

int CountDominant(const Node* t)
{
	if (TreeIsEmpty(t))
	{
		return 0;
	}
	
	int count = 0;
	CountDominantRec(t, &count);

	return count;
}