#include "reverse.h"

int Lenght(Item* i)
{
	int ris = 1;
	while (i->next != NULL)
	{
		ris++;
		i = i->next;
	}
	return ris;
}

Item* Reverse(Item* list, int right)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (right <= 1)
	{
		return list;
	}

	int len = Lenght(list);
	if (right > len)
	{
		right = len;
	}

	Item* prev = NULL;
	Item* curr = list;

	for (int i = 0; i < right && curr != NULL; i++)
	{
		Item* Next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = Next;
	}

	list->next = curr;
	list = prev;
	
	
	return list;
}
/*
int main(void)
{
	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	Item* i = ListCreateEmpty();

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = Reverse(i, 3);
	ListWriteStdout(ris);
	return 0;
}
*/