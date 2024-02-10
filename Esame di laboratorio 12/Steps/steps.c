#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void StepsRec(int n, int lvl, int* vcurr, int* nsol, int somma)
{
	if (somma == n)
	{
		printf("[");
		for (int i = 0; i < lvl; i++)
		{
			printf("%d", vcurr[i]);
			if (i != (lvl - 1))
			{
				printf(", ");
			}
		}
		printf("], ");
		(*nsol)++;
		return;
	}
	if (lvl == n)
	{
		return;
	}

	for (int j = 1; j <= 3; j++)
	{
		vcurr[lvl] = j;
		StepsRec(n, lvl + 1, vcurr, nsol, somma + j);
		vcurr[lvl] = 0;
	}
}


int Steps(int n)
{
	if (n <= 0)
	{
		return 0;
	}

	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	StepsRec(n, 0, vcurr, &nsol, 0);
	free(vcurr);
	return nsol;
}


/*
int main()
{
	int ris = Steps(6);

	return 0;
}
*/