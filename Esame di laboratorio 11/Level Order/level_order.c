#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


LevelAllOrderRec(const Node* t, int lvl, int* count, int choise)
{
	if (TreeIsEmpty(t))
	{
		return;
	}
	if(lvl > *count)
	{
		*count = lvl;
	}
	if (lvl == choise)
	{
		ElemWriteStdout(TreeGetRootValue(t));
		printf(" ");
	}
	LevelAllOrderRec(TreeLeft(t), lvl + 1, count, choise);
	LevelAllOrderRec(TreeRight(t), lvl + 1, count, choise);
}

void LevelOrder(const Node* t)
{
	if (t == NULL)
	{
		return;
	}
	int count = 0;
	LevelAllOrderRec( t, 0, &count, 50);

	for (int i = 0; i <= count; i++)
	{
		LevelAllOrderRec(t, 0, &count, i);
	}

	return;
}

/*
int main()
{
	ElemType e[] = { 7,4,2,1,5,8 };
	Node* r = TreeCreateEmpty();

	r = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 2,
					TreeCreateRoot(e + 3, NULL, NULL), NULL),
				TreeCreateRoot(e + 4, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL, NULL));

	LevelOrder(r);
	return 0;
}
*/