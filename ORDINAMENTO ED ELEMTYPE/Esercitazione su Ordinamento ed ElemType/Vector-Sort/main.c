#include "vettore.h"

int main(void)
{
	// stabilisco il mio vettore
	size_t n1 = 10;
	Vector* v = malloc(n1 * sizeof(Vector));

	v->capacity = n1;
	v->size = n1;
	v->data = malloc(n1 * sizeof(ElemType));

	//lo genero con numeri casuali e lo stampo in console
	srand(0);
	printf("il nostro vettore casuale disordinato e': \n");
	for (int i = 0; i < v->size; ++i)
	{
		v->data[i] = rand();
		ElemWriteStdout(&v->data[i]);
		printf("  ");
	}
	
	//richiamo la mia funzione
	VectorSort(v);

	printf("\nil nostro vettore casuale ordinato e': \n");
	for (int i = 0; i < v->size; ++i)
	{
		ElemWriteStdout(&v->data[i]);
		printf("  ");
	}
	
	//libero memoria e termino
	free(v->data);
	free(v);
	return EXIT_SUCCESS;
}