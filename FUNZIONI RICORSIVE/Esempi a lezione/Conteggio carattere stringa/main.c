/*Esercizio 4: 
Conteggio delle occorrenze di un 
carattere in una stringa
Realizzare una funzione ricorsiva 
che conta quante volte un certo carattere 
appare in una stringa data.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ConteggioCarattere(char* string, char *letter, int indice, int dim, int conteggio)
{
	if (indice >= dim)
	{
		return conteggio;
	}
	if (string[indice] == letter[0])
	{
		return ConteggioCarattere(string, letter, indice + 1, dim, conteggio + 1);
	}
	else
	{
		return ConteggioCarattere(string, letter, indice + 1, dim, conteggio);
	}
}

int main(void)
{
	char lettera[] = "s";
	char parola[] = "sassussolsso";
	int lunghezza = strlen(parola);
	int i = 0, c = 0;
	lunghezza--;

	int ris = ConteggioCarattere(parola, lettera, i, lunghezza, c);
	printf("le lettere totali sono %d", ris);
	return 0;
}