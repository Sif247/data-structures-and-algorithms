#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int SubsetkRec(int n, int k, bool* vcurr, int i, int* nsol, int count)
{
	//potatura
	if (count == 2)
	{
		(*nsol)++;
		printf("{ ");
		for (int j = 0; j < i; j++)
		{
			if (vcurr[j])
			{
				printf("%d,", j);
			}
		}
		printf(" }");
		return;
	}

	//caso base
	if (i == n)
	{
		return;
	}
	//soluzione neg
	vcurr[i] = 0;
	SubsetkRec(n, k, vcurr, i + 1, nsol, count);
	//soluzione pos
	vcurr[i] = 1;
	SubsetkRec(n, k, vcurr, i + 1, nsol, count + 1);
}

int Subsetk(int n, int k)
{
	bool* vcurr = malloc(k * sizeof(bool));
	int nsol = 0;
	SubsetkRec(n, k, vcurr, 0, &nsol, 0);
	return nsol;
}

int main(void)
{
	int ris = Subsetk(4, 2);
	return 0;
}
