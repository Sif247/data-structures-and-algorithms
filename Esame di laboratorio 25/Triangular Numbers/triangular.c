#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int Triangolo(int n, int ris)
{
	if (n == 0)
	{
		ris = 0;
		return ris;
	}
	else if(n == 1)
	{
		ris = 1;
		return ris;
	}
	else if (n == 2)
	{
		ris = 3;
		return ris;
	}
	ris = (3 * Triangolo(n - 1, ris)) - (3 * Triangolo(n - 2, ris)) + (Triangolo(n - 3, ris));
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
		
	ris = Triangolo(n, ris);

	printf("%d", ris);
	return 0;
}