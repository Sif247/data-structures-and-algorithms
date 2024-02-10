#define _CRT_SECURE_NO_WARNINGS
#include "differenza.h"
#include <string.h>
#include <stdio.h>

Item* Differenza(const Item* i1, const Item* i2)
{
	if (i1 == NULL && i2 == NULL)
	{
		return NULL;
	}
	if (i1 != NULL && i2 == NULL)
	{
		return i1;
	}
	ElemType rip = 0;
	ElemType diff = 0;
	Item* ris = ListCreateEmpty();
	ElemType tot[2] = { '\0', '\0' };
	while (i1 != NULL && i2 != NULL)
	{
	
		diff = (i1->value - '0') - rip - (i2->value - '0');
	

		if (diff < 0)
		{
			diff += 10;
			rip = 1;
		}
		else
		{
			rip = 0;
		}
		tot[0] = diff + '0';
		ris = ListInsertBack(ris, tot);
		i1 = i1->next;
		i2 = i2->next;
	}
	

	return ris;
}

/*

int main(void)
{
	ElemType e[] = "123";
	ElemType v[] = "123";

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (int i = 0; e[i] != 0; i++)
	{
		i1 = ListInsertBack(i1, e + i);
	}

	for (int j = 0; v[j] != 0; j++)
	{
		i2 = ListInsertBack(i2, v + j);
	}


	Item* result = Differenza(i1, i2);

	// Stampare il risultato
	printf("Risultato della differenza: ");
	ListWriteStdout(result);

	// Deallocazione della memoria delle liste e del risultato
	ListDelete(i1);
	ListDelete(i2);
	ListDelete(result);

	return 0;

}

*/
