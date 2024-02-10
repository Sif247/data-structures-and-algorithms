#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void PasswordsRec(int n, int* nsol, int* vcurr, int lvl)
{
	if (lvl == n)
	{
		bool esito = false;
		for (int i = 0; i < lvl - 1; ++i)
		{
			if (vcurr[i] <= vcurr[i + 1])
			{
				if (vcurr[i] == vcurr[i + 1])
				{
					esito = true;
				}
			}
			else
			{
				esito = false;
				break;
			}
		}
		if (esito)
		{
			(*nsol)++;
			printf("%d) ", *nsol);
			for (size_t i = 0; i < lvl; i++)
			{
				printf("%d", vcurr[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int j = 0; j < 10; j++)
	{
		vcurr[lvl] = j;
		PasswordsRec(n, nsol, vcurr, lvl + 1);
		vcurr[lvl] = 0;
	}
}

void Passwords(int n)
{
	int* vcurr = calloc(n, sizeof(int));
	int sol = 0;
	if (n < 0)
	{
		free(vcurr);
		return;
	}
	PasswordsRec(n, &sol, vcurr, 0);
	free(vcurr);
	return;
}
/*
int main()
{
	Passwords(2);
}
*/