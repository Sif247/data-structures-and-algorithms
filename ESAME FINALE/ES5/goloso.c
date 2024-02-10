#include "maxheap.h"
#include <stdlib.h>
#include <math.h>

// non ho usato la pop in quanto sappiamo già che il
// numero più grande è quello in posizione 0 essendo un maxheap

int MangiaCaramelle(Heap* h, int k)
{
	if (HeapIsEmpty(h))
	{
		return 0;
	}

	for (int i = 0; i < k; i++)
	{
		h->data[0] = sqrt(h->data[0]);
		HeapMaxMoveDown(h, 0);
	}

	int sum = 0;
	for (int j = 0; j < h->size; j++)
	{
		sum += h->data[j];
	}

	return sum;
}


/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->size = 5;
	h->data = calloc(h->size, sizeof(ElemType));

	h->data[0] = 100;	h->data[1] = 25;	h->data[2] = 64;
	h->data[3] = 9;		h->data[4] = 4;

	int ris = MangiaCaramelle(h, 4);

	HeapDelete(h);
	return 0;
}
*/