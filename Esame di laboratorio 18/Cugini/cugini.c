#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

void ControlloCuginiRec(Node* t, int b, int a, bool* esito)
{
	if (t == NULL)
	{
		return;
	}

	if ((t->left->value == a && t->right->value == b) || (t->left->value == b && t->right->value == a))
	{
		*esito = false;
	}

	ControlloCuginiRec(TreeLeft(t), a, b, esito);
	ControlloCuginiRec(TreeRight(t), a, b, esito);
}

void CuginiRec(Node* t, int lvl, int* fin_lvl,  int elem)
{
	if (t == NULL)
	{
		return;
	}

	if (t->value == elem)
	{
		*fin_lvl = lvl;
	}

	CuginiRec(TreeLeft(t), lvl + 1, fin_lvl, elem);
	CuginiRec(TreeRight(t), lvl + 1, fin_lvl, elem);
}

bool Cugini(const Node* t, int a, int b)
{
	if (t == NULL)
	{
		return false;
	}

	int lvl1 = 0;
	int lvl2 = 0;

	CuginiRec(TreeLeft(t), 0, &lvl1, a);
	CuginiRec(TreeRight(t), 0, &lvl2, b);

	if (lvl1 == lvl2)
	{
		bool esito = true;
		ControlloCuginiRec(t, a, b, &esito);
		return esito;
	}
	return false;

}

int main()
{
	Node* t = TreeCreateEmpty();
	ElemType e[] = {1,2,3,4,5,6,8};

	t = TreeCreateRoot(e,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 2, NULL, NULL),
				TreeCreateRoot(e + 3, NULL, NULL)),
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 5, NULL,
					TreeCreateRoot(e + 6, NULL, NULL)),NULL));

	bool ris1 = Cugini(t, 3, 4);

	bool ris2 = Cugini(t, 4, 6);

	return 0;
}