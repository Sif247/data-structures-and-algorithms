#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int IsPrime(int elem, int sott, bool* esito)
{
	if (sott == 1)
	{
		return sott;
	}
	if ((elem % sott) == 0)
	{
		*esito = false;
	}
	IsPrime(elem, sott - 1, esito);
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
	else if (n == 2)
	{
		printf("true");
		return 0;
	}
	else if (n <= 1)
	{
		printf("false");
		return 0;
	}

	int ris = 0;
	bool esito = true;
	ris = IsPrime(n, n - 1, &esito);

	if (esito)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}

	return 0;
}