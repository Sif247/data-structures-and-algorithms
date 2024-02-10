#include <stdlib.h>

int Recaman(int n)
{
	if (n < 1)
	{
		return -1;
	}
	if (n == 1)
	{
		return 1;
	}
	if (Recaman(n - 1) % (n - 1) == 0)
	{
		return Recaman(n - 1) / (n - 1);
	}
	else
	{
		return (n - 1) * Recaman(n - 1);
	}
	
}


/*
int main()
{
	int n = 6;
	int ris = 0;
	ris = Recaman(n);

	return 0;
}
*/