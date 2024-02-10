#include <stdio.h>
#include <math.h>

double Pi(double i, double *ris)
{
	if (i == 0)
	{
		return *ris = 4;
	}
	if ((int)i % 2 == 0)
	{
		return *ris = (4 * 1) / ((2 * i) + 1) + Pi((double)i - 1, ris);
	}
	else
	{
		return *ris = (4 * (-1)) / ((2 * i) + 1) + Pi((double)i - 1, ris);
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;//codice di errore
	}

	int n = atoi(argv[1]);
	if (n < 0)
	{
		return 1;//codice di errore
	}

	double ris;
	Pi(n, &ris);

	printf("%f", ris);
	return 0;
}