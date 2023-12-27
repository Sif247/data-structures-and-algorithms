#include "list.h"
#include <stdlib.h>

extern const ElemType* MaxElement(const Item* i);

int main(void)
{
	//ordine sparso
	{
		ElemType elem[] = { 3, 4, 2, 0, 45, 1 };
		Item* i = ListCreateEmpty();
		for (int j = 0; j < sizeof(elem) / sizeof(elem[0]); ++j)
		{
			i = ListInsertHead(&elem[j], i);
		}



		ElemType* ris = MaxElement(i);
		printf("%d\n", ris);
	}
	

	//ordine crescente
	{
		ElemType elem[] = { 1,2,3,4,5,6,7,8,9 };
		Item* i = ListCreateEmpty();
		for (int j = 0; j < sizeof(elem) / sizeof(elem[0]); ++j)
		{
			i = ListInsertHead(&elem[j], i);
		}
		ElemType* ris = MaxElement(i);
		printf("%d\n", ris);
	}

	//ordine decrescente
	{
		ElemType elem[] = { 9,8,7,6,5,4,3,2,1 };
		Item* i = ListCreateEmpty();
		for (int j = 0; j < sizeof(elem) / sizeof(elem[0]); ++j)
		{
			i = ListInsertHead(&elem[j], i);
		}
		ElemType* ris = MaxElement(i);
		printf("%d\n", ris);
	}

	return 0;
}