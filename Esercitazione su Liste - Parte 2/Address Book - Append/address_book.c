#include "list.h"

Item* Append(const Item* i1, const Item* i2)
{
	//variabile risultato
	Item* ris = ListCreateEmpty();
	//variabili temporanee
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	//controllo
	if (tmp1 == NULL && tmp2 == NULL)
	{
		return ris;
	}


	while (tmp1 != NULL)
	{
		ris = ListInsertBack(ris, &tmp1->value);
		tmp1 = ListGetTail(tmp1);
	}

	while (tmp2 != NULL)
	{
		ris = ListInsertBack(ris, &tmp2->value);
		tmp2 = ListGetTail(tmp2);
	}

	return ris;
}