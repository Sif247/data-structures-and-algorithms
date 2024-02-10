#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> 

bool Pop(Heap* h, ElemType* e)
{
	if (h->size == 0 || h == NULL)
	{
		return false;
	}

	*e = h->data[0];
	h->size -= 1;
	ElemSwap(&h->data[0], &h->data[h->size]);
	HeapMinMoveDown(h, 0);
	return true;
}


/*
int main()
{
	Heap* h = HeapCreateEmpty();
	h->size = 4;
	h->data = calloc(h->size, sizeof(ElemType));


	h->data[0] = 5;		h->data[1] = 2;
	h->data[2] = 14;	h->data[3] = 9;

	ElemType e = 0;
	bool ris = Pop(h, &e);

	return 0;

}
*/