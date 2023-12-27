#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void Permutazioni(int n, int i, int vcurr[], int* nsol) {
	int tmp;
	if (i == n) { // stampa soluzione
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = i; j < n; j++) {
		tmp = vcurr[i];
		vcurr[i] = vcurr[j];
		vcurr[j] = tmp;
		Permutazioni(n, i + 1, vcurr, nsol);
		tmp = vcurr[i];
		vcurr[i] = vcurr[j];
		vcurr[j] = tmp;
	}
}


int main() {
	int n = 4; // Dimensione dell'array di input
	int vcurr[] = { 1, 2, 3, 4 }; // Array di input
	int nsol = 0; // Contatore delle soluzioni

	printf("Permutazioni di lunghezza %d:\n", n);
	Permutazioni(n, 0, vcurr, &nsol);

	return 0;
}