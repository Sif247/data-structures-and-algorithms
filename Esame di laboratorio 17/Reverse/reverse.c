#include "list.h"
#include <stdlib.h>

Item* Reverse(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}
	Item* ris = NULL;

	while (i != NULL)
	{
		Item* tmp = i;
		i = i->next;
		tmp->next = ris;
		ris = tmp;
	}

	return ris;
}


/*
int main(void)
{
	Item* i = ListCreateEmpty();
	ElemType e[] = { 1,3,4,7,8 };

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = Reverse(i);

	return 0;
}
*/