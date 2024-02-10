#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, int lvl, char* vcurr, char* vbest, int pos)
{
	if (pos < 0)
	{
		return;
	}
	for (size_t i = 0; i < f_size; i++)
	{
		if (pos == f[i])
		{
			return;
		}
	}

	if (pos == h)
	{
		if (lvl <= *ret_size || *ret_size == 0)
		{
			for (size_t i = 0; i < lvl; i++)
			{
				vbest[i] = vcurr[i];
			}
			*ret_size = lvl;
		}
		return;
	}
	if (lvl == n)
	{
		return;
	}

	vcurr[lvl] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, lvl + 1, vcurr, vbest, pos + a);
	vcurr[lvl] = 'b';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, lvl + 1, vcurr, vbest, pos - b);

}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size)
{
	char* vcurr = calloc(n, sizeof(char) + 1);
	char* vbest = calloc(n, sizeof(char) + 1);
	*ret_size = 0;
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, 0, vcurr, vbest, 0);


	if (*ret_size == 0)
	{
		free(vcurr);
		return NULL;
	}
	else
	{
		free(vcurr);
		return vbest;
	}
}


/*
int main()
{
	int f[] = { 12, 4, 7, 1, 15 };
	int a = 3;
	int b = 15;
	int h = 9;
	int n = 2;
	size_t ret = 0;

	char* ris = GuidaLaPulce(f, 5, a, b, n, h, &ret);

	return 0;

}
*/
