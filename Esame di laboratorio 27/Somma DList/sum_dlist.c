#include "sum_dlist.h"
#include <stdlib.h>

Item* DListSum(const Item* i1, const Item* i2)
{
	if (i1 == NULL || i2 == NULL)
	{
		return NULL;
	}

	ElemType* ris = malloc(100* sizeof(ElemType));
	while (i1->next != NULL)
	{
		i1 = i1->next;
	}
	while (i2->next != NULL)
	{
		i2 = i2->next;
	}
	int c = 0; // count
	int r = 0; // resto

	while (i1 != NULL && i2 != NULL)
	{
		ElemType somma = i1->value + i2->value;
		if (somma < 9)
		{
			ris[c] = r + somma;
			r = 0;
		}
		else
		{
			somma %= 10;
			ris[c] = r + somma;
			r = 1;
		}
		c++;
		i1 = i1->prev;
		i2 = i2->prev;
	}

	Item* fin = DListCreateEmpty();

	if (i1 == NULL && i2 != NULL)
	{
		ElemType somma1 = r + i2->value;
		if (i2->value < 9)
		{
			ris[c] = i2->value;
		}
		else
		{
			somma1 %= 10;
			ris[c] = somma1;
			r = 1;
			c++;
			ris[c] = r;
		}
	}
	else if (i1 != NULL && i2 == NULL)
	{
		ElemType somma2 = r + i1->value;
		if (i1->value < 9)
		{
			ris[c] = i1->value;
		}
		else
		{
			somma2 %= 10;
			ris[c] = somma2;
			r = 1;
			c++;
			ris[c] = r;
			c++;
		}
	}

	for (int j = c - 1; j >= 0; j--)
	{
		fin = DListInsertBack(fin, &ris[j]);
	}

	free(ris);
	return fin;
}

/*
int main()
{
	ElemType e1[] = { 9, 5, 4 };
	ElemType e2[] = { 6, 9 };

	Item* list1 = DListCreateEmpty();
	Item* list2 = DListCreateEmpty();

	for (int i = 0; i < sizeof(e1) / sizeof(e1[0]); i++)
	{
		list1 = DListInsertBack(list1, e1 + i);
	}

	for (int j = 0; j < sizeof(e2) / sizeof(e2[0]); j++)
	{
		list2 = DListInsertBack(list2, e2 + j);
	}

	Item* ris = DListSum(list1, list2);
	DListWriteStdout(ris);


	DListDelete(list1);
	DListDelete(list2);
	DListDelete(ris);
	return 0;
}
*/