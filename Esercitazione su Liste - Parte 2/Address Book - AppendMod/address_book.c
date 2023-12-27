#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

Item* AppendMod(Item* i1, Item* i2)
{
	
	//variabili temporanee
	Item* tmp1 = i1;
	Item* tmp2 = i2;
	//controllo
	if (i1 == NULL && i2 == NULL)
	{
		return ListCreateEmpty();
	}
	else if (i1 == NULL && i2 != NULL)
	{
		return i2;
	}
	else if (i1 != NULL && i2 == NULL)
	{
		return i1;
	}

	//variabile di salvataggio
	Item* TMP = i1;

	//quando il puntatore finale è NULL copiarci i2
	for (; i1->next != NULL; i1 = ListGetTail(i1));
	i1->next = i2;
	//ritorna la variabile salvata
	return TMP;

}