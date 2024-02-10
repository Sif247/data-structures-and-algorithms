#include "cc.h"

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size)
{
	if (i == NULL || v == NULL || v_size == 0)
	{
		return 0;
	}

	bool esito = false;
	int controllo = 0;
	int ris = 0;
	while (i != NULL)
	{
		esito = false;
		for (int j = 0; j < v_size; j++)
		{
			if (i->value == v[j])
			{
				esito = true;
				controllo = 1;
			}
		}

		if (esito == false && controllo == 1)
		{
			ris++;
			controllo = 0;
			esito = false;
		}
		i = i->next;
	}
	if (esito)
	{
		ris++;
	}

	return ris;
}
/*
int main(void)
{
	ElemType e[] = { 0, 1, 3, 4};
	ElemType v[] = { 3};

	Item* i = ListCreateEmpty();
	size_t dim = sizeof(v) / sizeof(v[0]);

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	int ris = ComponentiConnesse(i, v, dim);
	return 0;


}
*/

