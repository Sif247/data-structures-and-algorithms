#include <stdlib.h>
#include <stdio.h>

typedef struct {
	size_t capacity;
	size_t size;
	int* data;
}Vector;

void NaiveSort(Vector *v)
{
	int tmp = 0;
	for (int j = 0; j < v->size - 1; ++j)
	{
		for (int i = j + 1; i < v->size; ++i)
		{
			if (v->data[j] > v->data[i])
			{
				tmp = v->data[j];
				v->data[j] = v->data[i];
				v->data[i] = tmp;
			}
		}
	}
	return;
}

void PushBack(Vector *v, int e)
{
	//SE LA CAPACITA NON BASTA SI RADDOPPIA E SI RIALLOCA LA MEMORIA 
	if (v->size == v->capacity)
	{
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(int) * v->capacity);
	}
	//RIEMPIAMO E AUMENTIAMO LA DIMENSIONE
	v->data[v->size] = e;
	v->size++;

	return;
}

int main(void)
{
	Vector v = { .capacity = 1, .size = 0, .data = calloc(1, sizeof(int)) };

	//RIEMPIAMO IL VETTORE
	srand(0);
	for (int i = 0; i < 20; ++i)
	{
		PushBack(&v, rand());
	}
	
	//ORA DOBBIAMO ORDINARE IL VETTORE DI NUMERI CASUALI CHEABBIAMO GENERATO
	//ANDIAMO CON IL "NAIVE SORT"
	NaiveSort(&v);

	printf("la capacita del vettore e' %zu\n", v.capacity);
	printf("la lunghezza del vettore e' %zu\n", v.size);
	printf("\nil vettore e' { ");
	for (int i = 0; i < v.size; ++i)
	{
		printf("%d, ", v.data[i]);	
	}
	printf("}\n");

	free(v.data);
	return 0;
}