#include "minheap.h"
#include <stdlib.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2)
{
	Heap* ris = HeapCreateEmpty();

	if (h1->size > 0 && h1 != NULL)
	{
		for (int i = 0; i < h1->size; i++)
		{
			HeapMinInsertNode(ris, h1->data + i);
		}
	}
	if (h2->size > 0 && h2 != NULL)
	{
		for (int j = 0; j < h2->size; j++)
		{
			HeapMinInsertNode(ris, h2->data + j);
		}
	}

	ris->size = h1->size + h2->size;
	return ris;

	
}

/*

int main(void)
{
	Heap* h1 = HeapCreateEmpty();
	Heap* h2 = HeapCreateEmpty();

	h1->data = malloc(sizeof(ElemType) * 6);
	h2->data = malloc(sizeof(ElemType) * 6);

	h1->size = 6;
	h2->size = 6;

	h1->data[0] = 2;		h1->data[1] = 7;		h1->data[2] = 5;
	h1->data[3] = 14;		h1->data[4] = 9;		h1->data[5] = 10;

	h2->data[0] = 1;		h2->data[1] = 6;		h2->data[2] = 8;
	h2->data[3] = 12;		h2->data[4] = 11;		h2->data[5] = 15;

	Heap* ris = MergeHeap(h1, h2);
	HeapWriteStdout(ris);

	HeapDelete(ris);
	return 0;
}
*/