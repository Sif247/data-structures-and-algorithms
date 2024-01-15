#include "minheap.h"
#include <stdlib.h>

void HeapMinMoveUpRec(Heap* h, int i)
{
	if (i == 0)
	{
		return;
	}
	if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0)
	{
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
		i = HeapParent(i);
		HeapMinMoveUpRec(h, i);
	}

}

/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->data = malloc(6 * sizeof(ElemType));
	h->size = 6;

	h->data[0] = 1;		h->data[1] = 4;		h->data[2] = 6;
	h->data[3] = 8;		h->data[4] = 2;		h->data[5] = 10;

	HeapMinMoveUpRec(h, 4);
	HeapWriteStdout(h);
	HeapDelete(h);
	return 0;
}
*/