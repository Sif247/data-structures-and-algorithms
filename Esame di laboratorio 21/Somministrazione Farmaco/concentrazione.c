#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Concetrazione(int n, double ris)
{
	if (n == 1)
	{
		return ris;
	}
	return ris = (0.3 * Concetrazione(n - 1, ris)) + 0.2;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		return 1;
	}

	int n = atoi(argv[1]);

	if (n < 1)
	{
		return 1;
	}

	double ris = 0;
	ris = Concetrazione(n, ris);
	printf("%f", ris);
	return 0;
}