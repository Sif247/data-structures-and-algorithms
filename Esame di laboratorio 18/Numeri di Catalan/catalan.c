#include <stdio.h>
#include <stdlib.h>

long long Catalan(long long n)
{
	if (n == 0)
	{
		return 1;
	}
	long long res = 0;
	for (int i = 0; i < n; i++)
	{
		res += catalan(i) * catalan(n - i - 1);
	}
	return res;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		return 1;
	}
	long long n = atoi(argv[1]);
	if (n < 0)
	{
		return 1;
	}

	long long ris = 0;
	ris = Catalan(n);

	printf("%lld", ris);
	return 0;
}