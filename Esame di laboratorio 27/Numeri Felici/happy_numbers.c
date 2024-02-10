#include <stdlib.h>
#include <stdio.h>

int happy(int n, int ris)
{
	if (ris == 1)
	{
		return ris;
	}
	else if (ris == 0 || ris == 4)
	{
		return ris;
	}
	ris = 0;
	while (n > 0) {
		int digit = n % 10;
		ris += digit * digit;
		n /= 10;
	}
	return happy(ris, ris);
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
		return 0;
	}
	int ris = -1;
	ris = happy(n, ris);

	if (ris == 1)
	{
		printf("Felice");
	}
	else
	{
		printf("Infelice");
	}
	return 0;
}