#include "vettore.h"

void BubbleSort(Vector* ris)
{
	int esito = 0;
	for (int i = 0; i < (ris->size - 1); ++i)
	{
		for (int j = (i + 1); j < ris->size - i - 1; ++j)
		{
			esito = ElemCompare(&ris->data[j], &ris->data[j + 1]);
			if (esito < 0)
			{
				ElemSwap(&ris->data[i], &ris->data[j]);
			}
		}
	}
}


Vector* VectorRead(const char* filename)
{
	//Apertura e Controllo
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		return NULL;
	}

	//allocazione dinamica
	Vector* ris = calloc(1, sizeof(Vector));
	ris->capacity = 1;
	ris->size = 0;
	ris->data = calloc(1, sizeof(ElemType));


	//lettura
	int var;
	while (1)
	{
		//scrittura diretta 
		var = ElemRead(file, &ris->data[ris->size]);
		//condizione di interruzione
		if (var <= 0)
		{
			break;
		}
		++(ris->size);
		//riaggiustamento allocazione e capacità
		if (ris->size == ris->capacity)
		{
			ris->capacity *= 2;
			ris->data = realloc(ris->data,ris->capacity * sizeof(ElemType));
		}
	}

	//chiusura e ritorno
	fclose(file);
	return ris;
}

Vector* VectorReadSorted(const char* filename)
{
	//Apertura e Controllo
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	//allocazione dinamica
	Vector* v = calloc(sizeof(Vector), 1);
	v->data = calloc(sizeof(ElemType), 1);
	v->size = 0;
	v->capacity = 1;

	int var;
	ElemType tmp;
	while (1) {
		//scrittura su variabile temporanea
		var = ElemRead(f, &tmp);
		if (var <= 0)
		{
			break;
		}
		//copio la variabile temporanea nella variabile ufficiale
		v->data[v->size] = tmp;

		//riaggiustamento capacità, memoria e dimensione
		++(v->size);
		if (v->size == v->capacity)
		{
			v->capacity *= 2;
			v->data = realloc(v->data, v->capacity * sizeof(ElemType));
		}
	}

	//SELECTION SORT

	int pos;
	for (int i = 0; i < v->size - 1; i++)
	{
		pos = i;
		for (int j = i + 1; j < v->size; ++j)
		{
			if (ElemCompare(&v->data[j], &v->data[pos]) < 0)
			{
				ElemSwap(&v->data[j], &v->data[pos]);
			}
		}
	}

	fclose(f);
	return v;
}