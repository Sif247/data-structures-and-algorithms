#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double fatt(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	return n * fatt(n - 1);
}

double Sen(int n, double x, double ris)
{
	ris += (pow(-1, n) * pow(x, 2 * n + 1)) / fatt(2 * n + 1);
	if (n == 0)
	{
		return ris;
	}
	return Sen(n - 1, x, ris);
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}

	double x = atof(argv[1]);
	int n = atoi(argv[2]);

	if (n < 0)
	{
		return 1;
	}

	double ris = 0;
	ris = Sen(n, x, ris);

	printf("%f", ris);
	return 0;
}
