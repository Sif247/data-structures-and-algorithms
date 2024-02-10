#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

ElemType KthLeast(const Heap* h, int k)
{
	if (h == NULL)
	{
		return 0;
	}
	ElemType ris = 0;

	qsort(h->data, h->size, sizeof(ElemType), ElemCompare);
	ris = h->data[k - 1];
	return ris;
	
}


/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->data = calloc(6, sizeof(ElemType));
	h->size = 6;

	h->data[0] = 7;		h->data[1] = 8;		h->data[2] = 9;
	h->data[3] = 4;		h->data[4] = 1;		h->data[5] = 15;

	ElemType ris = KthLeast(h, 3);
	return 0;
}
*/