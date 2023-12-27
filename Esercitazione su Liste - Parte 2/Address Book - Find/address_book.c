#include "list.h"

const ElemType* Find(const Item* i, const char* name)
{
	//controllo
	if (i == NULL)
	{
		return NULL;
	}
	//scorrimento
	while (i != NULL)
	{
		//confronto 
		if (ElemCompare(name, &i->value) == 0)
		{
			//ritorno del puntatore (avesse chiesto l'indirizzo sarebbe stato &i->value)
			return i;
		}
		i = ListGetTail(i);
	}
}