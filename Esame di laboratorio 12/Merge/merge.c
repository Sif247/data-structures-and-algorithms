#include "minheap.h"
#include <stdlib.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2)
{
	Heap* ris = HeapCreateEmpty();

	if (h1 == NULL && h2 == NULL)
	{
		return ris;
	}

	int count = 0;
	if (h1 == NULL)
	{
		while (count < h2->size)
		{
			HeapMinInsertNode(ris, h2->data + count);
			count++;
		}
		ris->size = h2->size;
		return ris;
	}
	if (h2 == NULL)
	{
		count = 0;
		while (count < h1->size)
		{
			HeapMinInsertNode(ris, h1->data + count);
			count++;
		}
		ris->size = h1->size;
		return ris;
	}

	count = 0;
	int count2 = 0;
	while (count < h1->size + h2->size)
	{
		if (count < h1->size)
		{
			HeapMinInsertNode(ris, h1->data + count);
		}
		else
		{
			HeapMinInsertNode(ris, h2->data + count2);
			HeapMinMoveUp(ris, count2);
			count2++;
		}
		count++;
	}
	ris->size = h1->size + h2->size;
	return ris;

}

/*

int main()
{
	Heap* h1 = HeapCreateEmpty();
	h1->data = calloc(4, sizeof(ElemType));
	h1->size = 4;
	h1->data[0] = 0;		h1->data[1] = 1;		
	h1->data[2] = 2;		h1->data[3] = 3;

	Heap* h2 = HeapCreateEmpty();
	h2->data = calloc(4, sizeof(ElemType));
	h2->size = 4;
	h2->data[0] = 5;		h2->data[1] = 4;
	h2->data[2] = 7;		h2->data[3] = 8;

	Heap* ris = MergeHeap(h1, h2);
	return 0;

}

*/