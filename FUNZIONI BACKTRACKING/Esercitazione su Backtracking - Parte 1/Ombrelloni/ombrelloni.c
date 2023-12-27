#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void OmbrelloniRec(int k, int n, bool* vcurr, int i, int *nsol, int count)
{
	//potatura
	if (count == k)
	{
		for (int j = 0; j < i - 1; ++j)
		{
			if (vcurr[j] == 1  && vcurr[j + 1] == 1)
			{
				return;
			}
		}
		(*nsol)++;
		printf("%d)", *nsol);
		for (int j = 0; j < n; ++j)
		{
			printf(" %d", vcurr[j]);
		}
		
		printf("\n");
		return;
	}

	if (i == n)
	{
		return;
	}
	

	//scelta neg
	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, count);

	//scelta pos
	vcurr[i] = 1;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, count + 1);
	vcurr[i] = 0;
}

int Ombrelloni(int k, int n)
{
	if (k < 0 || n < 0)
	{
		return 0;
	}

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);
	free(vcurr);
	return nsol;
}
/*
int main(void)
{
	int ris = Ombrelloni(2, 4);
	return 0;
}
*/