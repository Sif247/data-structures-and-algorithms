#include <stdio.h>
#include <stdlib.h>

int HailStone(int n, int* nsol)
{
	if (n == 1)
	{
		return 1;
	}
	printf("%d, ", n);
	(*nsol)++;
	if ((n % 2) == 0)
	{
		HailStone(n / 2, nsol);
	}
	else
	{
		HailStone((3 * n) + 1, nsol);
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		return -1;
	}

	int n = atoi(argv[1]);

	if (n <= 0)
	{
		return 0;
	}

	int nsol = 1;
	int ris = HailStone(n, &nsol);
	int fin = 1;
	printf("%d", fin);
	return nsol;


}