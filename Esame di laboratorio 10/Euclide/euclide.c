#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MCDRec(int m, int n)
{
	if (n == 0)
	{
		return m;
	}
	MCDRec(n, m % n);
}

int MCD(int m, int n)
{
	if (n > m)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}

	int ris = 0;
	ris = MCDRec( m, n);
	return ris;
}
/*
int main()
{
	int ris = MCD(12, 9);
	return 0;
}
*/