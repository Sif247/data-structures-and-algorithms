#include "list.h"

extern Item* IntersectNoRep(const Item* i1, const Item* i2);
extern Item* DiffNoRep(const Item* i1, const Item* i2);

int main(void)
{
	// valori 
	ElemType elem1[] = { 45, 8, 5, 2, 3, 45, 7, 5 };
	ElemType elem2[] = { 1, 3, 4, 2, 0, 45, 2, 1 };
	//lista e inserimento 1
	Item* i1 = ListCreateEmpty();
	for (int i = 0; i < sizeof(elem1) / sizeof(elem1[0]); i++)
	{
		i1 = ListInsertHead(&elem1[i], i1);
	}
	//lista e inserimento 2
	Item* i2 = ListCreateEmpty();
	for (int i = 0; i < sizeof(elem2) / sizeof(elem2[0]); i++)
	{
		i2 = ListInsertHead(&elem2[i], i2);
	}
	Item* ris;
	//chiamata e stampa
	ris = IntersectNoRep(i1, i2);
	ListWriteStdout(ris);

	ris = DiffNoRep(i1, i2);
	ListWriteStdout(ris);
	
	return 0;
}