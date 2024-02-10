#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void RegoleRec(size_t lvl, const char* r, int* vcurr, size_t dim)
{
	if (lvl == dim)
	{
		bool esito = true;

		for (int i = 0; i < dim - 1; i++)
		{
			for (int j = i + 1; j <= dim; j++)
			{
				if (vcurr[i] == vcurr[j])
				{
					esito = false;
					break;
				}
			}
		}

		for (int k = 0; k < dim - 1; k++)
		{
			if (vcurr[k] == vcurr[k + 1])
			{
				esito = false;
				break;
			}
			if (r[k] == 'D' || r[k] == 'd')
			{
				if (vcurr[k] < vcurr[k + 1])
				{
					esito = false;
					break;
				}
			}
			else if (r[k] == 'I' || r[k] == 'i')
			{
				if (vcurr[k] > vcurr[k + 1])
				{
					esito = false;
					break;
				}
			}
		}

		if (esito)
		{
			for (int i = 0; i < dim; i++)
			{
				printf("%d ", vcurr[i]);
			}
			printf("\n");
		}
		
		return;
	}

	for (int j = 1; j <= dim; j++)
	{
		vcurr[lvl] = j;
		RegoleRec(lvl + 1, r, vcurr, dim);
		vcurr[lvl] = 0;
	}
}

void Regole(const char* r)
{
	if (r == NULL)
	{
		return;
	}

	size_t dim = strlen(r) + 1;
	int* vcurr = calloc(dim, sizeof(int));
	RegoleRec(0, r, vcurr, dim);
	free(vcurr);
	return;
}
/*
int main()
{
	Regole("DI");
	return 0;
}
*/