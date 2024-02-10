#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int lvl, int* ris, int* vcurr)
{
	if (lvl == bis_size)
	{
		int dim = 0;
		for (int i = 0; i < bam_size; i++)
		{
			if (vcurr[i] >= bam[i])
			{
				dim++;
			}
		}
		if (dim > *ris)
		{
			*ris = dim;
		}

		return;
	}

	for (int i = 0; i < bis_size; i++)
	{
		vcurr[i] += bis[lvl];
		AssegnaBiscottiRec(bam, bam_size, bis, bis_size, lvl + 1, ris, vcurr);
		vcurr[i] -= bis[lvl];
	}
}


int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size)
{
	if (bam == NULL || bam_size == 0 || bis == NULL || bis_size == 0)
	{
		return 0;
	}

	int* vcurr = calloc(bam_size, sizeof(int));
	int ris = 0;
	
	AssegnaBiscottiRec(bam, bam_size, bis, bis_size, 0, &ris, vcurr);

	free(vcurr);
	return ris;
}


/*
int main(void)
{
	int bam[] = { 10, 20, 30 };
	int bis[] = { 10, 6, 7, 8 };


	int ris = AssegnaBiscotti(bam, 3, bis, 4);

	return 0;
}
*/