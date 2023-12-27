#include "vettore.h"


int main(void)
{
	//creamo il nostro Vector di 20 elementi
	Vector* v = calloc(20, sizeof(Vector));
	v->capacity = 20;
	v->size = 20;
	v->data = calloc(20, sizeof(Vector));

	//riempiamo il vettore in modo casuale tranne l'ultimo elemento
	srand(0);
	for (int i = 0; i < v->size - 1; ++i)
	{
		v->data[i] = rand();
	}
	//mettiamo nell'ultimo elemento il numero che ci serve
	v->data[v->size - 1] = 78;

	//BUBBLE SORT
	bool esito = true;

	while (esito)
	{
		esito = false;
		for (int i = 0; i < v->size - 1; ++i)
		{
			if (ElemCompare(&v->data[i], &v->data[i + 1]) > 0)
			{
				ElemSwap(&v->data[i], &v->data[i + 1]);
				esito = true;
			}
		}
	}

	//stampo il vettore nell'ordine giusto
	printf("IL VETTORE E':  \n");
	for (int i = 0; i < v->size - 1; ++i)
	{
		ElemWriteStdout(&v->data[i]);
		printf("  ");
	}

	//chiamo la funzione
	 
	//prova 1
	int find = 78;
	int pos = VectorFind(v, &find);
	if (pos != -1)
	{
		printf("\nl'elemento %d e' presente in posizione %d", find, pos);
	}
	else {
		printf("\nil numero non e' presente ");
	}

	// prova 2
	find = 2997;
	pos = VectorFind(v, &find);
	if (pos != -1)
	{
		printf("\nl'elemento %d e' presente in posizione %d", find, pos);
	}
	else {
		printf("\nil numero non e' presente ");
	}


	//libero e termino
	free(v->data);
	free(v);
	return EXIT_SUCCESS;
}
