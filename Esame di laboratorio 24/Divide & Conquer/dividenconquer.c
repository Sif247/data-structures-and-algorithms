#include <stdlib.h>
#include <stdio.h>

int Dividi(int n, int ris)
{
	if (n == 0)
	{
		ris = 0;
		return ris;
	}
	else if (n == 1)
	{
		ris = 1;
		return ris;
	}
	if (n % 2 == 0)
	{
		return ris = Dividi(n / 2, ris) + Dividi(n / 2, ris) + n;
	}
	return ris = Dividi(n / 2, ris) + Dividi(n / 2 + 1, ris) + n;
}

int main(int argc, char* argv[])
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

	int ris = 0;
	ris = Dividi(n, ris);

	printf("%d", ris);

	return 0;
}