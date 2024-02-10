#include "list.h"
#include <stdlib.h>

Item* Sum(const Item* i1, const Item* i2)
{
	Item* ris = ListCreateEmpty();
	if (i1 == NULL && i2 == NULL)
	{
		return ris;
	}
	else if (i1 == NULL)
	{
		while (i2 != NULL)
		{
			ris = ListInsertBack(ris, ListGetHeadValue(i2));
			i2 = i2->next;
		}
		return ris;
	}
	else if (i2 == NULL)
	{
		while (i1 != NULL)
		{
			ris = ListInsertBack(ris, ListGetHeadValue(i1));
			i1 = i1->next;
		}
		return ris;
	}

	int riporto = 0;
	int somma = 0;
	while (i1 != NULL && i2 != NULL)
	{
		somma = riporto + i1->value + i2->value;
		riporto = 0;
		if (somma > 9)
		{
			riporto = 1;
			somma %= 10;
		}
		ris = ListInsertBack(ris, &somma);
		i1 = i1->next;
		i2 = i2->next;
	}

	while (i1 != NULL)
	{
		somma = i1->value + riporto;
		riporto = 0;
		ris = ListInsertBack(ris, &somma);
		i1 = i1->next;
	}
	while (i2 != NULL)
	{
		somma = i2->value + riporto;
		riporto = 0;
		ris = ListInsertBack(ris, &somma);
		i2 = i2->next;
	}
	if (riporto == 1)
	{
		ris = ListInsertBack(ris, &riporto);
	}

	return ris;
}

/*
int main()
{
	ElemType e1[] = { 7, 2, 5, 4 };
	ElemType e2[] = { 3, 2, 4 };

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (int j1 = 0; j1 < sizeof(e1) / sizeof(e1[0]); j1++)
	{
		i1 = ListInsertBack(i1, e1 + j1);
	}

	for (int j2 = 0; j2 < sizeof(e2) / sizeof(e2[0]); j2++)
	{
		i2 = ListInsertBack(i2, e2 + j2);
	}

	Item* ris = Sum(i1, i2);
	return 0;
}
*/