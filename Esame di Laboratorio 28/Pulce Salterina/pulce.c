#include "pulce.h"

const Item* CalcolaPercorso(const Item* start, size_t n)
{
	if (start == NULL)
	{
		return NULL;
	}

	ElemType direzione = start->value;
	const Item* ris = start;

	if (ris->next == NULL && ris->prev == NULL)
	{
		return ris;
	}

	for (int i = 0; i < n; i++)
	{
		if(direzione == 0)
		{
			direzione = ris->value;
		}
		if (direzione > 0)
		{
			if (ris->next != NULL)
			{
				direzione--;
				ris = ris->next;
			}
			else
			{
				direzione = direzione * (-1);
				ris = ris->prev;
				direzione++;
			}
		}
		else if (direzione < 0)
		{
			if (ris->prev != NULL)
			{
				direzione++;
				ris = ris->prev;
			}
			else
			{
				direzione = direzione * (-1);
				ris = ris->next;
				direzione--;
			}
		}
	}

	return ris;


}