#include <stdio.h>
#include <stdlib.h>

void SubsetEqualRec(int n, int s, int* vcurr, int somma, int lvl)
{
	
	if (somma == s)
	{
		printf("{ ");
		for (int i = 0; i < lvl; i++)
		{
			printf("%d ", vcurr[i]);
		}
		printf("}, ");
		return;
	}
	if (lvl == n)
	{
		return;
	}

	for (int j = 1; j <= n; j++)
	{
		if (lvl == 0 || j > vcurr[lvl - 1])
		{
			vcurr[lvl] = j;
			SubsetEqualRec(n, s, vcurr, somma + j, lvl + 1);
			vcurr[lvl] = 0;
		}
		
	}
}

void SubsetEqual(int n, int s)
{
	if (n <= 0 || s <= 0)
	{
		return;
	}
	int* vcurr = calloc(n, sizeof(int));
	int somma = 0;
	SubsetEqualRec(n, s, vcurr, somma, 0);
	free(vcurr);
	return;
}


/*
int main()
{
	SubsetEqual(5, 7);
	return 0;
}
*/