#include "no_cycle.h"

void RemoveCycle(Item* i)
{
	if (ListIsEmpty(i))
	{
		return NULL;
	}

	Item* tmp1 = i;
	Item* tmp2 = i;

	while (tmp2 != NULL)
	{
		tmp2 = tmp2->next;
		while (tmp1 != tmp2)
		{
			if (tmp2->next == tmp1 || tmp2->next == tmp2)
			{
				tmp2->next = NULL;
				return i;
			}
			tmp1 = tmp1->next;
		}
		tmp1 = i;
	}

}

/*
int main()
{
	ElemType e[] = { 2, 5, 7, 6, 9 };
	Item* i = ListCreateEmpty();

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* tmp = i;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = i;

	RemoveCycle(i);
	ListDelete(i);
	return 0;
}
*/