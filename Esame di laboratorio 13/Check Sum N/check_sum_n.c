#include "tree.h"
#include <stdlib.h>

void CheckSumNRec(const Node* t, int n, int* arr, int *val)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	arr[*val] = t->value;
	(*val)++;
	CheckSumNRec(t->left, n, arr, val);
	CheckSumNRec(t->right, n, arr, val);
}

bool CheckSumN(const Node* t, int n)
{
	if (TreeIsEmpty(t))
	{
		return false;
	}

	int arr[200];
	int val = 0;
	CheckSumNRec(t, n, arr, &val);

	for (int i = 0; i < val - 1; i++)
	{
		for (int j = i + 1; j < val; j++)
		{
			if (arr[i] + arr[j] == n)
			{
				return true;
			}
		}
	}
	return false;


}

/*

int main()
{
	Node* r = TreeCreateEmpty();
	ElemType e[] = { 7,6,2,1,5,8 };

	r = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 2,
					TreeCreateRoot(e + 3, NULL, NULL), NULL),
				TreeCreateRoot(e + 4, NULL, NULL)),
			TreeCreateRoot(e + 5, NULL, NULL));


				

	bool ris = CheckSumN(r, 7);
	return 0;


}
*/