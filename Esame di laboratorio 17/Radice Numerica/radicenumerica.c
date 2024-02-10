#include<stdio.h>
#include <stdlib.h>

int SommaCifre(int n)
{
	int somma = 0;
	while (n != 0)
	{
		somma += n % 10;
		n /= 10;
	}
	return somma;
}

int Radice(int n, int somma)
{
	if (n < 10)
	{
		return n;
	}
	somma = SommaCifre(n);
	return Radice(somma, 0);
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

	int ris = Radice(n, 0);

	printf("%d", ris);
	return 0;
}