#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Item* ListLoad(const char* filename)
{
	//apertura file e controllo
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		return ListCreateEmpty();
	}

	//inizializzazioni
	Item* ris = ListCreateEmpty();
	ElemType valore = 0;
	int esito = 1;

	
	while (1)
	{
		//lettura da file
		esito = ElemRead(f, &valore);
		//verifica 
		if (esito == 0 || esito == EOF)
		{
			break;
		}
		//riempimento lista
		ris = ListInsertHead(&valore, ris);
	}
	//ritorno
	fclose(f);
	return ris;
}
