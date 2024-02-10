#include "tree.h"
#include <stdlib.h>
#include <float.h>

void MedianoRec(const Node* t, double* lenght, double* somma)
{
	if (TreeIsEmpty(t))
	{
		return;
	}

	MedianoRec(TreeLeft(t), lenght, somma);

	(*lenght)++;
	*somma += t->value;

	MedianoRec(TreeRight(t), lenght, somma);
}

double Mediano(const Node* t)
{
	if (t == NULL)
	{
		return DBL_MAX;
	}
	double somma = 0;
	double lenght = 0;
	MedianoRec(t, &lenght, &somma);

	double ris = somma / lenght;
	int confronto = ris;
	if (ris - confronto >= 0.05 && ris - confronto < 0.3)
	{
		ris = confronto + 0.5;
	}
	else if(ris - confronto > 0.3 && ris - confronto != 0.5)
	{
		ris = confronto + 1;
	}
	return ris;
}

/*
int main()
{
	ElemType e[] = { 7,4,2,1,5,8 };
	Node* t = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2,
				TreeCreateRoot(e + 3, NULL, NULL), NULL),
			TreeCreateRoot(e + 4, NULL, NULL)),
		TreeCreateRoot(e + 5, NULL, NULL));

	double ris = Mediano(t);
	return 0;
}
*/