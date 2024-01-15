#include "minheap.h"
#include <stdlib.h>

void HeapMinMoveDownRec(Heap* h, int i)
{
	if (i > (h->size - 1) / 2)
	{
		return;
	}

	size_t smallest = i;
	size_t left = HeapLeft(i);
	size_t right = HeapRight(i);

	if (left < h->size && ElemCompare(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, left)) > 0)
	{
		smallest = left;
	}

	if (right < h->size && ElemCompare(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, right)) > 0)
	{
		smallest = right;
	}

	if (smallest != i)
	{
		ElemSwap(HeapGetNodeValue(h, smallest), HeapGetNodeValue(h, i));
		HeapMinMoveDownRec(h, smallest);
	}
}
/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->data = malloc(sizeof(ElemType) * 5);
	h->size = 5;

	h->data[0] = 7;
	h->data[1] = 2;
	h->data[2] = 3;
	h->data[3] = 4;
	h->data[4] = 5;

	HeapMinMoveDownRec(h, 0);

	HeapDelete(h);
	return 0;
}
*/