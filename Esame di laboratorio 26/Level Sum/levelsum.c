#include "tree.h"

void LevelSumRec(const Node* t, size_t level, int curr, int* tot)
{
	if (t == NULL)
	{
		return;
	}
	if (level == curr)
	{
		*tot += t->value;
		return;
	}
	LevelSumRec(TreeLeft(t), level, curr + 1, tot);
	LevelSumRec(TreeRight(t), level, curr + 1, tot);
}


int LevelSum(const Node* t, size_t level)
{
	if (t == NULL)
	{
		return NULL;
	}
	int curr = 0;
	int tot = 0;
	LevelSumRec(t, level, curr, &tot);
	return tot;
}
/*
int main(void)
{
	ElemType e[] = { -2, 5, 8, -9, 2, 1, 1, 11 };

	Node* root = TreeCreateEmpty();

		root = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL,
				TreeCreateRoot(e + 3, NULL, NULL)),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 5, NULL,
			TreeCreateRoot(e + 6,
				TreeCreateRoot(e + 7, NULL, NULL), NULL)));

	int ris = LevelSum(root, 2);
	printf("%d", ris);
	return 0;

}
*/