#include "pulce.h"

int main(void)
{
	ElemType e[] = { 2, -3, 4, 1, 0, 5, -12, 3 };
	int n = 13;

	Item* list = DListCreateEmpty();
	int dim = sizeof(e) / sizeof(e[0]);

	for (int i = 0; i < dim; i++)
	{
		list = DListInsertBack(list,e + i);
	}

	Item* elem4 = list->next->next;
	Item* ris = CalcolaPercorso(elem4, n);

	return 0;

}