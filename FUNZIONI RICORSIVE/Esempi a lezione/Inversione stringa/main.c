/*Esercizio 3: Inversione di una stringa
Scrivere una funzione ricorsiva che inverte
una stringa. Ad esempio, se la stringa è "hello",
la funzione dovrebbe restituire "olleh".*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InvertiStringa(char* string, int indice, int dim)
{
	if (indice >= dim)
	{
		return;
	}
	else
	{
		char temp = string[indice];
		string[indice] = string[dim];
		string[dim] = temp;

		InvertiStringa(string, indice + 1, dim - 1);
	}
}

int main(void)
{
	char parola[] = "hello";
	int lenght = strlen(parola);

	printf("Stringa originale: %s\n", parola);
	InvertiStringa(parola, 0, lenght - 1);
	printf("Stringa invertita: %s\n", parola);

	return 0;
}