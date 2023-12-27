#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e)
{
	//controllo
	if (v == NULL || e == NULL || v->data == NULL || v->size == 0 || v->data == 0) 
	{
		return -1;
	}
	 
	 
	 
	//RICERCA BINARIA O DICOTOMICA
	
	int start, finish, position;
	start = 0;
	finish = v->size - 1;
	while (start <= finish)
	{
		position = (start + finish) / 2;
		if (v->data[position] == *e)
		{
			break;
		}
		else if (v->data[position] < *e)
		{
			start = position + 1;
		}
		else if (v->data[position] > *e)
		{
			finish = position - 1;
		}
	}

	//scelta del primo posto in caso di numeri uguali
	if (position == -1)
	{
		return position;
	}
	else
	{
		while (1)
		{
			if (position > 0 && v->data[position - 1] == *e)
			{
				position--;
			}
			else 
			{
				return position;
			}
		}
	}
}