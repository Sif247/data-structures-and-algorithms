#include "vettore.h"

void VectorSort(Vector* v)
{
	// Controllo se il puntatore v è valido
	if (v == NULL || v->data == NULL || v->size == 0 || v->capacity == 0) {
		return;
	}


	//BUBBLE SORT
	bool esito = true;

	while (esito)
	{
		esito = false;
		for (int i = 0; i < v->size - 1; ++i)
		{
			if (ElemCompare(&v->data[i], &v->data[i + 1]) > 0)
			{
				ElemSwap(&v->data[i], &v->data[i + 1]);
				esito = true;
			}
		}
	}

	return;
}