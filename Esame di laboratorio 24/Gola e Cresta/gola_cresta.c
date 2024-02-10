#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void GolaCrestaRec(size_t n, int* vcurr, int lvl)
{
	if (lvl == n)
	{
		bool esito = true;
		for (int i = 0; i < lvl - 2; i++)
		{
			if (vcurr[i] < vcurr[i + 1] && vcurr[i + 1] > vcurr[i + 2])
			{
				esito = true;
			}
			else if (vcurr[i] > vcurr[i + 1] && vcurr[i + 1] < vcurr[i + 2])
			{
				esito = true;
			}
			else
			{
				esito = false;
				break;
			}
		}

		if (esito)
		{
			printf("(");
			for (int i = 0; i < lvl; i++)
			{
				printf("%d, ", vcurr[i]);
			}
			printf("), ");
		}
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		vcurr[lvl] = i;
		GolaCrestaRec(n, vcurr, lvl + 1);
		vcurr[lvl] = 0;
	}
}

void GolaCresta(size_t n)
{
	int* vcurr = calloc(n, sizeof(int));
	GolaCrestaRec(n, vcurr, 0);
	free(vcurr);
	return;

}
/*
int main()
{
	unsigned val = 3;
	GolaCresta(val);
	return 0;
}
*/