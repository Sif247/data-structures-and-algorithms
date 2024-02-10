#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int Power(int n, int* c, int ris)
{
	if (n == ris)
	{
		return *c;
	}
	else if (ris > n)
	{
		*c = -1;
		return *c;
	}
	(*c)++;
	ris *= 4;
	return Power(n, c, ris);
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

	int ris = 1;
	int c = 0;
	ris = Power(n, &c, ris);

	if (c == -1)
	{
		printf("!p4");
		return 0;
	}
	
	printf("4^%d = %d", c, n);
	return 0;
}