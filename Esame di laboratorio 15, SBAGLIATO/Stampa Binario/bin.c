#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Binario(int n, int* save, int* dim)
{
	if (n == 0)
	{
		return 0;
	}
	save[*dim] = n % 2;
	(*dim)++;

	return Binario(n / 2, save, dim);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0)
	{
		return 1;
	}
	if (n == 0)
	{
		printf("%d", n);
		return 0;
	}

	int save[40];
	int dim = 0;
	int ris = 0;
	ris = Binario(n, save, &dim);

	for (int i = dim - 1; i >= 0; i--)
	{
		printf("%d", save[i]);
	}

	return 0;
}