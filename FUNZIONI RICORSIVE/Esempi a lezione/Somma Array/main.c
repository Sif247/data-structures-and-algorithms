/*Esercizio 1: Somma degli elementi in un array
Scrivere una funzione ricorsiva che calcola la somma di tutti gli elementi in un array di interi*/

#include <stdio.h>

int SommaArray(int* array, int lunghezza)
{
	//caso base
	if (lunghezza <= 0)
	{
		return 0;
	}
	else
	{
		//passo ricorsivo
		return array[lunghezza - 1] + SommaArray(array, lunghezza - 1);
	}
	
}

int main()
{
	int array[] = { 5,8,4,7,9 };
	int lunghezza = sizeof(array) / sizeof(array[0]);
	int risultato = SommaArray(array, lunghezza);
	return 0;
}