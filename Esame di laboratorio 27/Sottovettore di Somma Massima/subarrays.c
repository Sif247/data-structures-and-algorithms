#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void OptimalSubarrayRec(const int* v, size_t n, int lvl, bool* vcurr, bool* vbest, int* sommab)
{
	if (lvl == n)
	{
		int somma = 0;
		for (int i = 0; i < lvl; i++)
		{
			if (vcurr[i])
			{
				somma += v[i];
				if (vcurr[i + 1] == false)
				{
					break;
				}
			}
		}
		if (somma > *sommab)
		{
			*sommab = somma;
			memcpy(vbest, vcurr, lvl * sizeof(bool));
		}
		return;
	}

	vcurr[lvl] = false;
	OptimalSubarrayRec(v, n, lvl + 1, vcurr, vbest, sommab);
	vcurr[lvl] = true;
	OptimalSubarrayRec(v, n, lvl + 1, vcurr, vbest, sommab);
	vcurr[lvl] = false;
}

int OptimalSubarray(const int* v, size_t n)
{
	if (n == 0)
	{
		return 0;
	}
	bool* vcurr = calloc(n, sizeof(bool));
	bool* vbest = calloc(n, sizeof(bool));
	int sommabest = 0;
	OptimalSubarrayRec(v, n, 0, vcurr, vbest, &sommabest);
	free(vbest);
	free(vcurr);
	return sommabest;
}
/*
int main()
{
	int v[] = { 1, 2, 3, 4, 5, 6 };
	int dim = sizeof(v) / sizeof(v[0]);

	int ris = OptimalSubarray(v, dim);
	printf("%d", ris);
	return 0;
}
*/