#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL)
	{
		return NULL;
	}

	int linee = 0;
	char ch;
	while (!feof(f))
	{
		ch = fgetc(f);
		if (ch == '\n')
		{
			linee++;
		}
	}

	fseek(f, 0, SEEK_SET);
	Gioiello* risfin = calloc(linee + 1, sizeof(Gioiello));

	int i = 0;
	while (fscanf(f, "%d %f %f", &risfin[i].codice, &risfin[i].peso, &risfin[i].prezzo) == 3)
	{
		i++;
	}

	float somma = 0;
	Gioiello tmp;
	for (int j = 0; j < i; j++)
	{
		if ((j != i - 1) && risfin[j].prezzo > risfin[j + 1].prezzo)
		{
			tmp = risfin[j];
			risfin[j] = risfin[j + 1];
			risfin[j + 1] = tmp;
		}
	}
	for (int j = 0; j < i; j++)
	{
		somma += risfin[j].prezzo;
		if (somma <= budget)
		{
			(*ret_size)++;
		}
	}
	Gioiello* ris = calloc(*ret_size, sizeof(Gioiello));
	for (int k = 0; k < *ret_size; k++)
	{
		ris[k] = risfin[k];
	}
	fclose(f);
	free(risfin);
	ris = realloc(ris, sizeof(Gioiello) * (*ret_size));
	return ris;
}
/*
int main(void)
{
	const char filename1[] = "gioielli_1.txt";
	size_t dim1 = 0;
	Gioiello* ris1 = CompraGioielli(filename1, 121, &dim1);

	const char filename2[] = "gioielli_2.txt";
	size_t dim2 = 0;
	Gioiello* ris2 = CompraGioielli(filename2, 121, &dim2);

	return 0;
}
*/
