/*Esercizio 2: 
Ricerca di un elemento in un array.
Implementare una funzione ricorsiva che ricerca un elemento specifico
in un array di interi restituendo la sua posizione se viene trovato, altrimenti -1.*/

#include <stdlib.h>
#include <stdio.h>

int RicercaArray(int* arr, int n, int indice)
{
	if (indice >= n)
	{
		return -1;
	}
	if (arr[indice] == 8)
	{
		return indice;
	}
	else
	{
		return RicercaArray(arr, n, indice + 1);
	}
}

int main(void)
{
	int array[] = { 5,6,7,8,2 };
	int lunghezza = sizeof(array) / sizeof(array[0]);
	int ris = RicercaArray(array, lunghezza, 0);
	return 0;

}