#include <stdio.h>
#include <stdlib.h>

#define N 5
#define DOUBLE_MAX 1000000

typedef struct {
	double costo;    // costo soluzioni
	int stazione[N];  // lista fermate
} piano;



void StazioniServizio(double M, int n, double* d, double* p, int i, double dist, piano c, piano* b, double PercorsoDaUltimoRifornimento)
{

	if (i == n) {
		for (int i = 0; i < n; i++)
		//getchar();
		if (c.costo < b->costo) {
			b->costo = c.costo;  // copia piano attuale in b
			//printf("Trovato best (%f)",b->costo);
			for (int i = 0; i < n; i++) {
				b->stazione[i] = c.stazione[i];
				//printf("\n%d",b->stazione[i]);
			}
		}
		return;
	}

	dist += d[i];
	PercorsoDaUltimoRifornimento += d[i];


	// non è possibile arrivare a questa stazione di servizio
	//600km e' la distanza percorribile con un pieno
	if (PercorsoDaUltimoRifornimento > 600)
		return;

	c.stazione[i] = 0;
	//printf("\nSalto Rifornimento in stazione %d, (percorsi %f km)", i, dist);
	StazioniServizio(M, n, d, p, i + 1, dist, c, b, PercorsoDaUltimoRifornimento);

	c.costo += PercorsoDaUltimoRifornimento * 0.05 * p[i]; // aggiungo costo di rifornirmi in i
	c.stazione[i] = 1;
	PercorsoDaUltimoRifornimento = 0;
	//printf("\nRifornimento in stazione %d, (percorsi %f km)", i, dist);
	StazioniServizio(M, n, d, p, i + 1, dist, c, b, PercorsoDaUltimoRifornimento);
}



void main()
{
	double M = 0;
	piano corrente, best;
	int n = N;
	double distanza[N], prezzo[N];

	for (int i = 0; i < N; i++) {
		corrente.stazione[i] = 0;
		best.stazione[i] = 0;
		prezzo[i] = i + 35 - i * i;
		distanza[i] = 260 + i * 24;
		M += distanza[i];
	}

	corrente.costo = 0;
	best.costo = DOUBLE_MAX;


	StazioniServizio(M, n, distanza, prezzo, 0, 0, corrente, &best, 0);

	if (best.costo == DOUBLE_MAX)
		printf("\nImpossibile raggiungere la meta");
	else {
		printf("\n\nConviene fare il pieno nelle stazioni: ");
		for (int i = 0; i < n; i++)
			if (best.stazione[i] == 1)
				printf("\n%d", i);
		printf("\nCosto totale: %.2f ", best.costo);
	}
}

