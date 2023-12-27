#include "list.h"
#include <stdlib.h>

size_t Lenght(const Item* i)
{
	Item* tmp = i;
	size_t count = 0;
	while (tmp != ListCreateEmpty())
	{
		count++;
		tmp = ListGetTail(tmp);
	}
	return count;
}

Item* Reverse(const Item* i)
{
	//variabile risultato
	Item* ris = ListCreateEmpty();

	//controllo
	if (i == NULL)
	{
		return ris;
	}
	
	//chiamo la funzione per sapere la lunghezza
	size_t size = Lenght(i);

	//lista temporanea 
	Item* tmp = i;

	//Array di Elemtype su dove copiare gli elementi 
	ElemType* Lista = calloc(size, sizeof(ElemType));

	//copiamo dalla variabile temporanea 
	int j = 0;
	while (tmp != ListCreateEmpty())
	{
		Lista[j] = ElemCopy(&tmp->value);
		j++;
		tmp = ListGetTail(tmp);
	}

	for (int k = size - 1; k >= 0; --k)
	{
		ris = ListInsertBack(ris, &Lista[k]);
	}

	free(Lista);
	return ris;
}