#include <stdlib.h>

int Potenza(int a, int b)
{
	if (b < 1)
	{
		return 1;
	}
	if (b == 1)
	{
		return a;
	}
	return a * Potenza(a, b - 1);
}

/*
int main(void)
{
	int ris = Potenza(0, 0);
	return 0;
}
*/