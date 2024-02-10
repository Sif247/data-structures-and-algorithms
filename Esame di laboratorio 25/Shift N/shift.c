#include "shift.h"

int LenList(Item* list)
{
	int ris = 1;
	while (list->next != NULL)
	{
		ris++;
		list = list->next;
	}
	return ris;
}

Item* ShiftN(Item* list, size_t n)
{
	if (list == NULL)
	{
		return NULL;
	}

	if (n == 0)
	{
		return list;
	}

	int len = LenList(list);
	n %= (len - 1);
	if (n == 0)
	{
		n = (len - 1);
	}

	Item* First = list;
	Item* Start = list->next;
	for (int i = 0; i < n; i++)
	{
		list = list->next;
	}
	First->next = list->next;
	list->next = First;

	return Start;
    
}

/*
int main(void)
{
	ElemType e[] = { 0, 1, 2, 3 };
	Item* i = ListCreateEmpty();

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); ++j)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = ShiftN(i, 3);
	ListWriteStdout(ris);
	ListDelete(i);
	ListDelete(ris);
	return 0;
}
*/