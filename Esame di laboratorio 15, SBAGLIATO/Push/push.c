#include "minheap.h"
#include <stdlib.h>

void Push(Heap* h, const ElemType* e)
{
	if (h == NULL)
	{
		return;
	}

	HeapMinInsertNode(h, e);

	return;
}

/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->size = 4;
	h->data = calloc(h->size, sizeof(ElemType));

	h->data[0] = 8;		h->data[1] = 4;
	h->data[2] = 2;		h->data[3] = 7;
	ElemType b = 14;

	Push(h, &b);

	return 0;
}
*/
