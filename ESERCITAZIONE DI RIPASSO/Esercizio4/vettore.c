#include "vettore.h"

void Push(struct vettore* v, int d)
{
	v->size += 1;
	v->data = realloc(v->data, v->size * sizeof(int));
	v->data[v->size - 1] = d;
}

int Pop(struct vettore* v)
{
	int rimoss = v->data[0];
	v->size -= 1;
	for (int i = 0; i < v->size; i++)
	{
		v->data[i] = v->data[i + 1];
	}
	v->data = realloc(v->data, (v->size) * sizeof(int));

	return rimoss;
}