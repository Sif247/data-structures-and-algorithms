#include "list.h"
#include <stdlib.h>

Item* Rotate(Item* i, int n)
{
	if (i == NULL)
	{
		return NULL;
	}

	Item* curr = i;

	for (int i = 0; i < n; i++)
	{
		curr = curr->next;
	}
	Item* fin = curr;
	
	while (fin->next != 0)
	{
		fin = fin->next;
	}
	
	fin->next = i;
	for (int i = 0; i < n; i++)
	{
		fin = fin->next;
	}
	fin->next = NULL;


	return curr;
}

/*
int main()
{
	Item* i = ListCreateEmpty();
	ElemType e[] = { 1, 3, 4, 7, 8 };
	int n = 2;

	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item *ris = Rotate(i, n);
	
	return 0;
}
*/