#include "minheap.h"
#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k)
{
	if (HeapIsEmpty(h) || k < 0 || k >= h->size)
	{
		return;
	}

	h->data[k] = h->data[h->size - 1];
	h->size -= 1;
	HeapMinMoveDown(h, k);

	h->data = realloc(h->data, sizeof(ElemType) * (h->size));

	return;
}


/*
int main()
{
	Heap* e = HeapCreateEmpty();
	e->size = 4;
	e->data = malloc(e->size * sizeof(ElemType));

	e->data[0] = 5;		e->data[1] = 2;
	e->data[2] = 9;		e->data[3] = 8;

	HeapDeleteNode(e, 2);
	return 0;
}
*/
