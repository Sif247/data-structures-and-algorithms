#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void ParentesiRec(int n, int lvl, bool* vcurr, int* nsol)
{
	if (lvl == (n * 2))
	{
		int open = 0;
		int close = 0;
		int sort = 0;

		for (int i = 0; i < n * 2; i++)
		{
			if (vcurr[i])
			{
				open++;
			}
			else 
			{
				close++;
				if (open < close)
				{
					return;
				}
			}
		}
		if (close == open)
		{
			(*nsol)++;
			for (int i = 0; i < n * 2; i++)
			{
				if (vcurr[i])
				{
					printf("(");
				}
				else
				{
					printf(")");
				}
			}
			printf("\n");
		}
		return;
	}

	vcurr[lvl] = false;
	ParentesiRec(n, lvl + 1, vcurr, nsol);
	vcurr[lvl] = true;
	ParentesiRec(n, lvl + 1, vcurr, nsol);
	vcurr[lvl] = false;

}

int Parentesi(int n)
{
	if (n < 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}

	bool* vcurr = calloc(n * 2, sizeof(bool));
	int nsol = 0;
	ParentesiRec(n, 0, vcurr, &nsol);
	free(vcurr);
	return nsol;
}
/*
int main()
{
	int val = 0;
	int ris = Parentesi(val);
}
*/