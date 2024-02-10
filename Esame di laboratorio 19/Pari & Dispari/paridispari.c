#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

int Lenght(Item* i)
{
	int ris = 0;
	while (i != NULL)
	{
		ris++;
		i = i->next;
	}
	return ris;
}

Item* PariDispari(Item* i)
{
	if (ListIsEmpty(i) || i->next == NULL)
	{
		return i;
	}
	Item* inizio = i;
	Item* prev = i;
	Item* curr = i->next;

	int dim = Lenght(i);

	while (curr != NULL && dim != 1)
	{
		dim--;
		if (curr->value % 2 != 0)
		{
			prev->next = curr->next;
			curr->next = NULL;
			while (i->next != NULL)
			{
				i = i->next;
			}
			i->next = curr;
			i = inizio;
			curr = prev->next;
		}
		else
		{
			prev = prev->next;
			curr = curr->next;
		}
	}

	if (i->value % 2 != 0)
	{
		Item* ris = i;
		i = i->next;
		Item* scorr = i;
		while (scorr->next != NULL)
		{
			scorr = scorr->next;
		}

		scorr->next = ris;
		ris->next = NULL;


		return i;
	}


	return i;
}

/*

int main()
{
	Item* i = ListCreateEmpty();
	ElemType e[] = { 1,8,7,6,9,3,5,2 };
	for (int j = 0; j < sizeof(e) / sizeof(e[0]); j++)
	{
		i = ListInsertBack(i, e + j);
	}

	Item* ris = PariDispari(i);

	return 0;
}
*/