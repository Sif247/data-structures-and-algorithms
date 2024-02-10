#include "list.h"
#include <stdlib.h>

Item* ElementiPari(const Item* i)
{
	if (ListIsEmpty(i))
	{
		return ListCreateEmpty();
	}

	Item* ris = ListCreateEmpty();
	int count = 0;
	while (i != NULL)
	{
		if (count % 2 == 0 || count == 0)
		{
			ris = ListInsertBack(ris, ListGetHeadValue(i));
		}
		count++;
		i = i->next;
	}

	return ris;
}


/*
int main()
{
	Item* i = ListCreateEmpty();

	ElemType e[] = { 7, 2, 5, 8, 6, 4 };
	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = ElementiPari(i);
	return 0;
}
*/