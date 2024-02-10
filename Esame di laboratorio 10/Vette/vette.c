#include "list.h"
#include <stdbool.h>

int ContaVette(const Item* i)
{
	if (i == NULL)
	{
		return 0;
	}
	int ris = 0;
	bool esito = true;
	for (Item* tmp = i; tmp != NULL; tmp = tmp->next)
	{
		for (Item* tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
		{
			if (tmp->value < tmp2->value)
			{
				esito = false;
				break;
			}
		}
		if (esito)
		{
			ris++;
		}
		esito = true;
	}
	return ris;
}
/*
int main()
{
	ElemType e[] = { 7, 2, 5, 4 };
	Item* i = ListCreateEmpty();
	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	int ris = ContaVette(i);
	return 0;
}
*/