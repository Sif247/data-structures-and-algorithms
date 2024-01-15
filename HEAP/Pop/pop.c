#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool HeapMinPop(Heap* h, ElemType* e)
{
	if (HeapIsEmpty(h) || e == NULL)
	{
		return false;
	}

	*e = ElemCopy(h->data);
	h->data[0] = h->data[h->size - 1];
	h->size -= 1;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	HeapMinMoveDown(h, 0);
	
	return true;
}


/*
int main()
{

	Heap* h = HeapCreateEmpty();
	h->data = malloc(6 * sizeof(ElemType));
	h->size = 6;
	h->data[0] = 1;		h->data[1] = 2;		h->data[2] = 3;
	h->data[3] = 4;		h->data[4] = 5;		h->data[5] = 6;

	ElemType min = 0;
	bool ris = HeapMinPop(h, &min);
	HeapWriteStdout(h);
	HeapDelete(h);
	return 0;
}
*/