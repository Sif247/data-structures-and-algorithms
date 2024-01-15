#include "minheap.h"

Heap* HeapMinHeapify(const ElemType* v, size_t v_size)
{
	Heap* ris = HeapCreateEmpty();

	if (v_size == 0 || v == NULL)
	{
		return ris;
	}

	for (int i = 0; i < v_size; i++)
	{
		HeapMinInsertNode(ris, v + i);
	}
	return ris;

}


/*
int main()
{
	ElemType e[] = { 1,2,3,4,5,6,7,8 };
	size_t dim = sizeof(e) / sizeof(e[0]);

	Heap* ris = HeapMinHeapify(e, dim);
	HeapWriteStdout(ris);
	HeapDelete(ris);
	return 0;
}
*/