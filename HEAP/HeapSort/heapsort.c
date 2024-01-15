#include "minheap.h"
#include <stdlib.h>

void HeapMinHeapsort(Heap* h)
{
	if (h == NULL)
	{
		return;
	}
	size_t dim = h->size;
	while (h->size > 1)
	{
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size -= 1;
		HeapMinMoveDown(h, 0);
	}
	h->size = dim;
}

/*

int main()
{
	Heap* h = HeapCreateEmpty();
	h->data = malloc(sizeof(ElemType) * 6);
	h->size = 6;
	h->data[0] = 5;		h->data[1] = 3;		h->data[2] = 8;
	h->data[3] = 12;	h->data[4] = 7;		h->data[5] = 2;

	HeapMinHeapsort(h);
	HeapWriteStdout(h);
	HeapDelete(h);
	return 0;
}

*/