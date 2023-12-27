#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int i, bool* vcurr, bool* vbest, int somma, int count, int *countbest)
{
	//case base
	if (i == pacchi_size)
	{
		//verification the solution
		for (int j = 0; j < i; j++)
		{
			if (vcurr[j])
			{
				somma += pacchi[j];
			}
		}
		if (somma <= 0 || somma > p)
		{
			return;
		}
		else if (count > *countbest)
		{
			*countbest = count;
			for (int k = 0; k < i; k++)
			{
				vbest[k] = vcurr[k];
			}
		}
		return;
	}

	//negative solution
	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, somma, count, countbest);

	//positive solution
	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, somma, count + 1, countbest);
	
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p)
{
	bool* vcurr = malloc(pacchi_size * sizeof(bool));
	bool* vbest = malloc(pacchi_size * sizeof(bool));
	int sommabest = 0;
	int countbest = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, 0, 0, &countbest);
	for (int a = 0; a < pacchi_size; a++)
	{
		printf("%d ", vbest[a]);
	}
	free(vcurr);
	free(vbest);
	return;
}
/*
int main(void)
{
	int p = 20;
	const int pacchi[] = { 10, 11, 1, 3, 3 };
	int pacchi_size = sizeof(pacchi) / sizeof(pacchi[0]);
	BabboNatale(pacchi, pacchi_size, p);
	return 0;
}
*/
