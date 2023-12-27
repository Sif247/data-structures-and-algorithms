#include "list.h"

Item* Filtra(const Item* i, const char* city)
{
	Item* ris = ListCreateEmpty();
	if (i == NULL)
	{
		return ris;
	}

	while (i != ListCreateEmpty())
	{
		if (ElemCompare(&i->value.city, city) == 0)
		{
			ris = ListInsertBack(ris, &i->value);
			i = ListGetTail(i);
			continue;
		}
		i = ListGetTail(i);
	}
	return ris;
}